#include <stdio.h>
#include "get_req.h"
#include <string.h>
#include "api_key.h" // #define API_KEY myapikey

static const char *TAG = "http client";
#define MAX_RESPONSE_LEN 1024

esp_err_t _http_event_handler(esp_http_client_event_t *evt)
{
    static char *output_buffer;  // Buffer to store response of http request from event handler
    static int output_len;       // Stores number of bytes read
    switch(evt->event_id) {
        case HTTP_EVENT_ERROR:
            ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:
            ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
            break;
        case HTTP_EVENT_ON_DATA:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
            /*
             *  Check for chunked encoding is added as the URL for chunked encoding used in this example returns binary data.
             *  However, event handler can also be used in case chunked encoding is used.
             */
            if (!esp_http_client_is_chunked_response(evt->client)) {
                // If user_data buffer is configured, copy the response into the buffer
                if (evt->user_data) {
                    memcpy(evt->user_data + output_len, evt->data, evt->data_len);
                } else {
                    if (output_buffer == NULL) {
                        output_buffer = (char *) malloc(esp_http_client_get_content_length(evt->client));
                        output_len = 0;
                        if (output_buffer == NULL) {
                            ESP_LOGE(TAG, "Failed to allocate memory for output buffer");
                            return ESP_FAIL;
                        }
                    }
                    memcpy(output_buffer + output_len, evt->data, evt->data_len);
                }
                output_len += evt->data_len;
            }

            break;
        case HTTP_EVENT_ON_FINISH:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
            if (output_buffer != NULL) {
                // Response is accumulated in output_buffer. Uncomment the below line to print the accumulated response
                // ESP_LOG_BUFFER_HEX(TAG, output_buffer, output_len);
                free(output_buffer);
                output_buffer = NULL;
                output_len = 0;
            }
            break;
        case HTTP_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
            int mbedtls_err = 0;
            esp_err_t err = esp_tls_get_and_clear_last_error(evt->data, &mbedtls_err, NULL);
            if (err != 0) {
                if (output_buffer != NULL) {
                    free(output_buffer);
                    output_buffer = NULL;
                    output_len = 0;
                }
                ESP_LOGI(TAG, "Last esp error code: 0x%x", err);
                ESP_LOGI(TAG, "Last mbedtls failure: 0x%x", mbedtls_err);
            }
            break;
    }
    return ESP_OK;
}

// initialize GET request params and http client, perform transfer, cleanup then return response
esp_err_t make_get_request(char * const resp_buf, const char * query)
{
	char local_response_buf[MAX_RESPONSE_LEN] = {0};

	esp_http_client_config_t config = {
		.url = "https://covid-19-data.p.rapidapi.com/report/country/all",
		.query = query,
		.event_handler = _http_event_handler,
		.user_data = local_response_buf
	};
	esp_http_client_handle_t client = esp_http_client_init(&config);
	esp_err_t err = esp_http_client_set_header(client, "x-rapidapi-host", "covid-19-data.p.rapidapi.com");
	err = esp_http_client_set_header(client, "x-rapidapi-key", API_KEY);
	err = esp_http_client_perform(client);

	if (err == ESP_OK) {
	ESP_LOGI(TAG, "Status = %d, content_length = %d",
			esp_http_client_get_status_code(client),
			esp_http_client_get_content_length(client));
	}
	ESP_LOG_BUFFER_HEX(TAG, local_response_buf, MAX_RESPONSE_LEN);
    // local_response_buf[esp_http_client_get_content_length(client)] = '\0'; // terminate request string
	snprintf(resp_buf, MAX_RESPONSE_LEN, "%s", local_response_buf);

	esp_http_client_cleanup(client);
	return err;
}
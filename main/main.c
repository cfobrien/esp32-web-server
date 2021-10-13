/* HTTP File Server Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <sys/param.h>

#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_spiffs.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "protocol_examples_common.h"

#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_tls.h"

#include "get_req.h"
#include "write_file.h"

#define REPLACE_AT(rdst, doff, rsrc, roff, rlen) for (int ri = 0; ri < rlen; ri++) rdst[doff+ri] = rsrc[roff+ri]

static const char *TAG = "web app";
static char filename_template[] = "/spiffs/NA.txt";
static char line_template[] = "Date(DD/MM/YYYY) Daily deaths:(XXXX) Total deaths:(XXXX)\n";

/* This example demonstrates how to create file server
 * using esp_http_server. This file has only startup code.
 * Look in file_server.c for the implementation */

/* Function to initialize SPIFFS */
static esp_err_t init_spiffs(void)
{
    ESP_LOGI(TAG, "Initializing SPIFFS");

    esp_vfs_spiffs_conf_t conf = {
      .base_path = "/spiffs",
      .partition_label = NULL,
      .max_files = 5,   // This decides the maximum number of files that can be created on the storage
      .format_if_mount_failed = true
    };

    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Failed to mount or format filesystem");
        } else if (ret == ESP_ERR_NOT_FOUND) {
            ESP_LOGE(TAG, "Failed to find SPIFFS partition");
        } else {
            ESP_LOGE(TAG, "Failed to initialize SPIFFS (%s)", esp_err_to_name(ret));
        }
        return ESP_FAIL;
    }

    size_t total = 0, used = 0;
    ret = esp_spiffs_info(NULL, &total, &used);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to get SPIFFS partition information (%s)", esp_err_to_name(ret));
        return ESP_FAIL;
    }

    ESP_LOGI(TAG, "Partition size: total: %d, used: %d", total, used);
    return ESP_OK;
}

/* Declare the function which starts the file server.
 * Implementation of this function is to be found in
 * file_server.c */
esp_err_t start_file_server(const char *base_path);

typedef struct {
    char * isocode;
    const char * date;
} api_params_t;


static void get_and_write_api_response(void *pvParameters)
{
    api_params_t * p_params = (api_params_t *)pvParameters;

    // overwrite previous country code
    REPLACE_AT(filename_template, 8, p_params->isocode, 0, 2);

    // overwrite previous date with following format
    //"Date(DD/MM/YYYY) Daily deaths:(XXXX) Total deaths:(XXXX)\n";
    //"2020-04-01"
    REPLACE_AT(line_template, 5, p_params->date, 8, 2);
    REPLACE_AT(line_template, 8, p_params->date, 5, 2);
    REPLACE_AT(line_template, 11, p_params->date, 0, 4);

    write_line(filename_template, line_template);
    vTaskDelete(NULL);
}


void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    ESP_ERROR_CHECK(example_connect());

    /* Initialize file storage */
    ESP_ERROR_CHECK(init_spiffs());

    static api_params_t api_params = {
        .isocode = "it",
        .date = "2020-04-01"
    };
    xTaskCreate(&get_and_write_api_response, "get_and_write_api_response", 8192, &api_params, 5, NULL);

    // const char * isocode = "it";
    // static char buf[MAX_RESPONSE_LEN] = {0};
    // ESP_ERROR_CHECK(make_get_request(buf, isocode));
    // printf("%s\n", buf);

    /* Start the file server */
    ESP_ERROR_CHECK(start_file_server("/spiffs"));
}

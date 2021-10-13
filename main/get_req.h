#ifndef GET_REQ_H
#define GET_REG_H

#include "esp_event.h"
#include "esp_system.h"
#include "esp_http_client.h"
#include "esp_log.h"
#include "esp_tls.h"

#define MAX_RESPONSE_LEN 1024

esp_err_t _http_event_handler(esp_http_client_event_t * evt);

esp_err_t make_get_request(char * const resp_buf, const char * url);

#endif // GET_REQ_H
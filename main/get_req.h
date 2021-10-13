#ifndef GET_REQ_H
#define GET_REG_H

#include "esp_event.h"
#include "esp_system.h"
#include "esp_http_client.h"
#include "esp_log.h"
#include "esp_tls.h"

static char filename_template[] = "/spiffs/NA.txt";
static char line_template[] = "Date(DD/MM/YYYY) Daily deaths:(XXXX) Total deaths:(XXXX)\n";
static char query_template[] = "code=XX&date=YYYY-MM-DD";

#define MAX_RESPONSE_LEN 1024
static char response_buf[MAX_RESPONSE_LEN] = {0};

esp_err_t _http_event_handler(esp_http_client_event_t * evt);

esp_err_t make_get_request(char * const resp_buf, const char * query);

#endif // GET_REQ_H
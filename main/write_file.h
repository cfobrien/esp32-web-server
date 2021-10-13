#ifndef WRITE_FILE_H
#define WRITE_FILE_H

#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spiffs.h"

esp_err_t write_line(const char * filename, const char * contents);

#endif
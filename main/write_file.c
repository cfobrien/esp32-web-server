#include "write_file.h"

static const char *TAG = "file uploader";

esp_err_t write_line(const char * filename, const char * contents) {
    ESP_LOGI(TAG, "Opening file");

    FILE* f = fopen(filename, "a");    
    
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for writing");
    }
    fprintf(f, "%s", contents);
    fclose(f);
    ESP_LOGI(TAG, "File written");

	return ESP_OK;
}
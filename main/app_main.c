#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <nvs_flash.h>
#include "wifi_prov_ble.h"
#include "mqtt_tcp.h"
#include <esp_log.h>

static const char *TAG = "main app";

void app_main(void)
{
     /* Initialize NVS partition */
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        /* NVS partition was truncated
         * and needs to be erased */
        ESP_ERROR_CHECK(nvs_flash_erase());

        /* Retry nvs_flash_init */
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    wifi_prov_ble("PROV_", "abcd1234", "custom-data", 2, true);

    esp_mqtt_client_config_t mqtt_cfg = 
      {
        .broker.address.uri = "mqtt://host:port",
        .credentials.username = "user",
        .credentials.authentication.password = "pass",
    };

    mqtt_tcp(mqtt_cfg);  

    mqtt_tcp_subscribe("data/irrigator/010-111", 0);

    while(1){
        mqtt_tcp_publish("data/irrigator/010-00111", "irrigator test", 0, 0);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }

}

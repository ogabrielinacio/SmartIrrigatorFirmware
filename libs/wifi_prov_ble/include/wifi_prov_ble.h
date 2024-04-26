#pragma once

#include <stdio.h>
#include <string.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>

#include <esp_log.h>
#include "esp_wifi.h"
#include <esp_event.h>

#include <wifi_provisioning/manager.h>

#include <wifi_provisioning/scheme_ble.h>

#include "qrcode.h"

#include <stdbool.h>

void wifi_prov_ble(char *ssid_prefix, char *password,
                char *custom_endpoint,
                int max_retries_after_wifi_connection_failed,
                bool show_qr_code);

void wifi_prov_ble_reset_wifi();
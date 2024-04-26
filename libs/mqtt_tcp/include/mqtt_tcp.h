#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

#include "esp_log.h"
#include "mqtt_client.h"

void mqtt_tcp(esp_mqtt_client_config_t mqtt_cfg);

int mqtt_tcp_publish(char *topic, char *data, int qos, int retain);
 
int mqtt_tcp_subscribe(char *topic, uint8_t qos);
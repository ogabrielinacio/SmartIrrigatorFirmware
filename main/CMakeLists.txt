idf_component_register(SRCS "app_main.c" 
                    "../libs/wifi_prov_ble/wifi_prov_ble.c"
                    "../libs/mqtt_tcp/mqtt_tcp.c"
                    INCLUDE_DIRS "."  
                        "../libs/wifi_prov_ble/include"
                        "../libs/mqtt_tcp/include"
                        )

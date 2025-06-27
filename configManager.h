#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "memeeprom.h"
#include <ESP.h>



typedef struct {
    uint16_t id;
    char ssid[128];
    char password[128];
    uint16_t interval; // em minutos
} DeviceConfig;

void configManager_init();
void configManager_load();
void configManager_save();
void configManager_reset();
uint16_t configManager_get_id();
char* configManager_get_ssid();
char* configManager_get_password();
uint16_t configManager_get_interval();
void configManager_poll();
bool configManager_update_from_json(const char* json_str);

#endif
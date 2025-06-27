#include "configManager.h"

static DeviceConfig current_config;

void configManager_init() {
  memeeprom_init();
  configManager_load();
}

void configManager_load() {
  current_config.id = memeeprom_readByte(MEMEEPROM_ID_ADDRESS);
  memeeprom_readString(MEMEEPROM_SSID_ADDRESS, current_config.ssid);
  memeeprom_readString(MEMEEPROM_PASSWORD_ADDRESS, current_config.password);
  current_config.interval = memeeprom_read2Bytes(MEMEEPROM_INTERVAL_ADDRESS);
}

void configManager_save() {
  memeeprom_writeByte(MEMEEPROM_ID_ADDRESS, current_config.id);
  memeeprom_write2Bytes(MEMEEPROM_INTERVAL_ADDRESS, current_config.interval);
  memeeprom_writeString(MEMEEPROM_SSID_ADDRESS, current_config.ssid);
  memeeprom_writeString(MEMEEPROM_PASSWORD_ADDRESS, current_config.password);
}

uint16_t configManager_get_id() {
  return current_config.id;
}

char* configManager_get_ssid() {
  return current_config.ssid;
}

char* configManager_get_password() {
  return current_config.password;
}

uint16_t configManager_get_interval() {
  return current_config.interval;
}

void configManager_poll() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.startsWith("CONFIG:")) {
      String jsonStr = input.substring(7);

      if (configManager_update_from_json(jsonStr.c_str())) {
        Serial.println("CONFIG_OK");
        Serial.print("Novo ID: ");
        Serial.println(configManager_get_id());

        ESP.restart();  // Reinício limpo

      } else {
        Serial.println("CONFIG_ERROR");
      }
    }
  }
}

bool configManager_update_from_json(const char* json_str) {
  char id_aux[10], interval_aux[10];
  StaticJsonDocument<256> doc;

  DeserializationError error = deserializeJson(doc, json_str);

  if (error) return false;

  strlcpy(id_aux, doc["id"] | id_aux, sizeof(id_aux));
  Serial.print("ID RECEBIDO: ");
  Serial.println(id_aux);
  current_config.id = atoi(id_aux);

  strlcpy(current_config.ssid, doc["ssid"] | current_config.ssid, sizeof(current_config.ssid));
  strlcpy(current_config.password, doc["password"] | current_config.password, sizeof(current_config.password));
  strlcpy(interval_aux, doc["interval"] | interval_aux, sizeof(interval_aux));

  Serial.print("INTERVAL RECEBIDO: ");
  Serial.println(interval_aux);
  current_config.interval = atoi(interval_aux);

  configManager_save();
  return true;
}
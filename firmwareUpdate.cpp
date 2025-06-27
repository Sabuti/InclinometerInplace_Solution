#include "firmwareUpdate.h"

HTTPClient http;
const char* firmware_url = "http://145.223.29.194:8003/enviar_firmware/firmware.bin"; // URL do novo firmware

void firmwareUpdate_check() {
  http.begin(firmware_url);

  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    int contentLength = http.getSize();
    WiFiClient* stream = http.getStreamPtr();

    if (!Update.begin(contentLength)) {
      Serial.println("Falha ao iniciar atualização!");
      return;
    }

    Serial.println("Baixando firmware...");
    size_t written = Update.writeStream(*stream);
    if (written == contentLength) {
      Serial.println("Download concluído!");
    } else {
      Serial.println("Erro no download!");
    }

    if (Update.end()) {
      Serial.println("Atualização completa. Reiniciando...");
      ESP.restart();
    } else {
      Serial.println("Erro na atualização!");
    }
  }
  http.end();
}
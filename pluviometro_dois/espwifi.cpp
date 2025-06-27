#include "espwifi.h"
//#include "http.h"


// Configuração do Wi-Fi
// const char* ssid = "TP-Link_202";
// const char* password = "@Condominio202";
char* ssid;
char* password;


void espwifi_init() {
  uint8_t count = 0;
  ssid = configManager_get_ssid();
  password = configManager_get_password();
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("Password: ");
  Serial.println(password);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    count++;
    Serial.print("Conectando ao WiFi... status: ");
    Serial.print(WiFi.status());
    Serial.print(" RSSI: ");
    Serial.println(WiFi.RSSI());
    if (count >= 20) {
      WiFi.disconnect();  // Reseta a conexão
      WiFi.reconnect();   // Tenta reconectar
      count = 0;
      delay(5000);
      Serial.println("Nao Conectou ao WiFi!!!");
      return;
    }
  }
  Serial.println("Conectado ao WiFi");
  digitalWrite(LED_WIFI_CONN, LOW);
}

int8_t espwifi_getSignal() {
  return WiFi.RSSI();
}

bool espwifi_poll() {
  // if (WiFi.status() != WL_CONNECTED) {
  //   digitalWrite(LED_WIFI_CONN, LOW);
  //   Serial.println("WiFi desconectado. Tentando reconectar...");
  //   WiFi.begin(ssid, password);
  //   return 0;
  // } else {
  //   digitalWrite(LED_WIFI_CONN, HIGH);
  return true;
  //}
}

//bool espwifi_sendData(MPU6050_DATA_PTR sensorMPU) {
  //bool success = true;
  //if (WiFi.status() == WL_CONNECTED) {
    //success &= http_post_Analytics(sensorMPU);
    //success &= http_post_Instruments(sensorMPU);
  //} else {
  //  return false;
 // }
  //return success;
//}
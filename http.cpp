#include "http.h"
#include "espwifi.h"

//const char* serverAnalytics_send = "http://145.223.29.194:8001/receber_dados";
//const char* serverAnalytics_receive = "http://145.223.29.194:8002/enviar_configuracoes";
//const char* serverInstruments_send = "https://backend.solution-ipd.com/weather-data";

//bool http_post_Analytics(MPU6050_DATA_PTR sensorMPU) {
  //HTTPClient http;

  //http.begin(serverAnalytics_send);
  //http.addHeader("Content-Type", "application/json");

  // Criando JSON
  //StaticJsonDocument<200> jsonDocument;
  //jsonDocument["light"] = sensorWS90SL->lightValue;
  //jsonDocument["UVI"] = sensorWS90SL->uviValue;
  //jsonDocument["temperature"] = sensorWS90SL->temperatureValue;
  //jsonDocument["humidity"] = sensorWS90SL->humidityValue;
  //jsonDocument["windSpeed"] = sensorWS90SL->windValue;
  //jsonDocument["gust"] = sensorWS90SL->gustValue;
  //jsonDocument["windDir"] = sensorWS90SL->windDirectionValue;
  //jsonDocument["rainfall"] = sensorWS90SL->rainfallValue;
  //jsonDocument["ABSPress"] = sensorWS90SL->absPressureValue;
  //jsonDocument["rainCounter"] = sensorWS90SL->rainCounterValue;
  //jsonDocument["id"] = configManager_get_id();
  //jsonDocument["rssi"] = espwifi_getSignal();
  //String jsonString;
  //serializeJson(jsonDocument, jsonString);
  //int httpResponseCode = http.POST(jsonString);
  //http.end();
  //if (httpResponseCode > 0) {
    //Serial.println("Dados enviados com sucesso Analytics: " + String(httpResponseCode));
    //return true;
  //} else {
    //Serial.println("Erro ao enviar dados Analytics: " + String(httpResponseCode));
    //return false;
  //}
//}

//bool http_post_Instruments(WS90SL_DATA_PTR sensorWS90SL) {
  //HTTPClient http;

  //http.begin(serverInstruments_send);
  //http.addHeader("Content-Type", "application/json");

  // Criando JSON
  //StaticJsonDocument<200> jsonDocument;
  //jsonDocument["light"] = sensorWS90SL->lightValue;
  //jsonDocument["UVI"] = sensorWS90SL->uviValue;
  //jsonDocument["temperature"] = sensorWS90SL->temperatureValue;
  //jsonDocument["humidity"] = sensorWS90SL->humidityValue;
  //jsonDocument["windSpeed"] = sensorWS90SL->windValue;
  //jsonDocument["gust"] = sensorWS90SL->gustValue;
  //jsonDocument["windDir"] = sensorWS90SL->windDirectionValue;
  //jsonDocument["rainfall"] = sensorWS90SL->rainfallValue;
  //jsonDocument["ABSPress"] = sensorWS90SL->absPressureValue;
  //jsonDocument["rainCounter"] = sensorWS90SL->rainCounterValue;
  //jsonDocument["id"] = configManager_get_id();
  //jsonDocument["rssi"] = espwifi_getSignal();
  //String jsonString;
  //serializeJson(jsonDocument, jsonString);
  //int httpResponseCode = http.POST(jsonString);
  //http.end();
  //if (httpResponseCode > 0) {
    //Serial.println("Dados enviados com sucesso Instruments: " + String(httpResponseCode));
    //return true;
  //} else {
    //Serial.println("Erro ao enviar dados Instruments: " + String(httpResponseCode));
    //return false;
  //}
//}

// void http_getConfigurations(CONFIG_DATA_PTR configData) {
//   HTTPClient http;

//   http.begin(serverAnalytics_receive);
//   int httpCode = http.GET();

//   if (httpCode == HTTP_CODE_OK) {
//     String payload = http.getString();

//     // Parse do JSON
//     DynamicJsonDocument doc(1024);
//     deserializeJson(doc, payload);

//     // Lendo configurações
//     configData->tempoEntreConexao = doc["tempoEntreConexao"];

//     Serial.print("tempoEntreConexao: ");
//     Serial.println(configData->tempoEntreConexao);
//   }
//   http.end();
// }
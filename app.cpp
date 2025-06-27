#include "app.h"
//#include "http.h"

static uint64_t app_t_millis;
static uint64_t app_sensor_millis;


void app_init() {
  sensorMPU.deviceName = 0x68;
  sensorMPU.dataRate = 2;
  sensorMPU.deviceAddress = 0x68;
  sensorMPU.accelx = 0;
  sensorMPU.accely = 0;
  sensorMPU.accelz = 0;
  sensorMPU.gyrox = 0;
  sensorMPU.gyroy = 0;
  sensorMPU.gyroz = 0;
  sensorMPU.temp = 0;                  
  app_t_millis = millis();
  app_sensor_millis = millis();
  mpu6050_readHoldingRegister(&sensorMPU);
  Serial.print("ID: ");
  Serial.println(configManager_get_id());

  Serial.print("Intervalo de medidas: ");
  Serial.println(configManager_get_interval());
}

bool app_timer_1s() {
  if (millis() > app_t_millis + (1000)) {
    app_t_millis = millis();
    return true;
  } else {
    return false;
  }
}

bool app_timer_sensor(uint32_t value_m) {
  if (millis() > app_sensor_millis + (value_m * 1000 * 60)) {
    app_sensor_millis = millis();
    return true;
  } else {
    return false;
  }
}

void app_poll() {
  mpu6050_processTasks();
  if (app_timer_1s) {
    if (espwifi_poll()) {
      firmwareUpdate_check();
      //http_getConfigurations(&configData);
    }
  }
  if (app_timer_sensor(configManager_get_interval())) {
    Serial.println(configManager_get_interval());
    for (uint8_t i = 0; i < TENTATIVAS_DE_CONEXAO; i++) {
      if (mpu6050_readHoldingRegister(&sensorMPU)) {
        //if (espwifi_sendData(&sensorMPU))
          return;
      } else {
        delay(1000);
      }
    }
  }
}
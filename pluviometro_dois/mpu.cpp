#include "mpu.h"

#define DEBUG

HardwareSerial RS485Serial(2);              // Usando Serial2 para comunicação RS485
ModbusRTU modbus;                           // Criando instância do Modbus
uint16_t readValues[NUM_SENSOR_REGISTERS];
MPU6050_DATA_T sensorMPU;  // Array para armazenar os valores lidos

void mpu6050_init(void) {

  // Configura a Serial2 para comunicação RS485
  RS485Serial.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);  // TX = GPIO 17, RX = GPIO 16

  // Configura o Modbus
  modbus.begin(&RS485Serial, RS485_DE_RE);
  modbus.master();  // Define como mestre Modbus

  Serial.println("Iniciando comunicação Modbus...");
}

void mpu6050_processTasks() {
  modbus.task();  // Processa requisição
}

bool mpu6050_readHoldingRegister(MPU6050_DATA_PTR sensorMPU) {
  uint16_t allZeroMeasures = 0;
  if (!modbus.slave()) {  // Se não estiver processando outra requisição
    if (modbus.readHreg(SLAVE_WHOAMI_ID, ADDRESS_ACCELXOUT_H, readValues, NUM_SENSOR_REGISTERS)) {
      for(uint8_t i = 0; i<10; i++){
        allZeroMeasures = allZeroMeasures | readValues[i];
      }
      if(allZeroMeasures == 0){
        return false;
      }
      
      sensorMPU->accelx = readValues[0];          // Obtém os dados do registrador;
      sensorMPU->accely = readValues[1];            // Obtém os dados do registrador;
      sensorMPU->accelz = readValues[2];    // Obtém os dados do registrador;
      sensorMPU->temp = readValues[3];       // Obtém os dados do registrador;
      sensorMPU->gyrox = readValues[4];           // Obtém os dados do registrador;
      sensorMPU->gyroy = readValues[5];           // Obtém os dados do registrador;
      sensorMPU->gyroz = readValues[6];  // Obtém os dados do registrador;
      //sensorMPU->rainfallValue = readValues[7];       // Obtém os dados do registrador;
      //sensorMPU->absPressureValue = readValues[8];    // Obtém os dados do registrador;
      //sensorMPU->rainCounterValue = readValues[9];    // Obtém os dados do registrador;
#ifdef DEBUG
      /*Serial.println("Dado do sensor MPU6050: ");
      Serial.print("light Value: ");
      Serial.println(sensorMPU->accelx);
      Serial.print("UVI Value: ");
      Serial.println(sensorWS90SL->uviValue);
      Serial.print("temperature Value: ");
      Serial.println(sensorWS90SL->temperatureValue);
      Serial.print("humidity Value: ");
      Serial.println(sensorWS90SL->humidityValue);
      Serial.print("wind Value: ");
      Serial.println(sensorWS90SL->windValue);
      Serial.print("gust Value: ");
      Serial.println(sensorWS90SL->gustValue);
      Serial.print("wind direction Value: ");
      Serial.println(sensorWS90SL->windDirectionValue);
      Serial.print("rainfall Value: ");
      Serial.println(sensorWS90SL->rainfallValue);
      Serial.print("ABS pressure Value: ");
      Serial.println(sensorWS90SL->absPressureValue);
      Serial.print("rainfall counter Value: ");
      Serial.println(sensorWS90SL->rainCounterValue);
      */
#endif
  return true;
    }
  } else {
    Serial.println("Erro ao ler registradores!");
    return false;
  }
}

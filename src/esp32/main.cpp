#include <Arduino.h>
#include <ModbusRTUMaster.h>

#define TXD 15
#define RXD 16
#define RTS 17

HardwareSerial RS485Serial(2);
ModbusRTUMaster master;

uint16_t response[10];  // buffer para armazenar valores lidos

void setup() {
  Serial.begin(115200);
  RS485Serial.begin(9600, SERIAL_8N1, RXD, TXD);
  master.begin(RS485Serial, RTS);
}

void loop() {
  static uint32_t last = 0;

  if (millis() - last > 1000) {
    last = millis();

    // Lê 1 registrador do escravo ID 1, endereço 0
    if (master.readHoldingRegisters(1, 0, response, 1)) {
      Serial.print("Valor lido do escravo: ");
      Serial.println(response[0]);
    } else {
      Serial.println("Falha na leitura.");
    }
  }
}

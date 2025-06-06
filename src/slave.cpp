#include <Wire.h>
#include <Arduino.h>

void setup() {
    Wire.begin(0x08); // como escravo com endereço 0x08
    Wire.onReceive(receberDados); // callback para dados recebidos
}

void receberDados(int qtd) {
    while(Wire.available()) {
        char c = Wire.read();
        Serial.print(c);
  }
}

#include "slave.h"

void slave_init(void) {
    Wire.begin(0x08); // como escravo com endereço 0x08
    //Wire.onReceive(receberDados); // callback para dados recebidos
    //rever motivo do erro ao chamar a função
}

void enviarDados(int qtd) {
    while(Wire.available()) {
        char c = Wire.read();
        Serial.print(c);
  }
}
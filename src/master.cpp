// exemplo básico
#include <Wire.h>
#include <Arduino.h>

int main(){
    Wire.begin(); // como mestre

  while (true){
    Wire.beginTransmission(0x08); // endereço do escravo
    Wire.write("Oi");             // envia dados
    Wire.endTransmission();       // finaliza transmissão
    delay(200);
  }
}



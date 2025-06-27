#include "pins.h"

void pins_init() {

  // Configura o pino de controle do RS485 (DE/RE)
  // pinMode(RS485_DE_RE, OUTPUT);
  // digitalWrite(RS485_DE_RE, LOW);  // Modo recepção por padrão

  // Configura os LED's
  pinMode(LED_POWER_ON, OUTPUT);
  digitalWrite(LED_POWER_ON, LOW);  // LED indicativo de código rodando

  pinMode(LED_WIFI_CONN, OUTPUT);
  digitalWrite(LED_WIFI_CONN, HIGH);  // LED indicativo de conexão wifi
}
#include <ModbusRTU.h>

#define RS485_TX 21   // GPIO 17
#define RS485_RX 22   // GPIO 16
#define RS485_DE_RE 4 // GPIO 33

ModbusRTU mb;

const uint8_t NUM_ESCRAVOS = 10; // alterar conforme precisa
const uint8_t idEscravos[NUM_ESCRAVOS] = {1,2,3,4,5,6,7,8,9,10}; // IDs dos escravos

uint16_t dadoLido;
uint8_t escravoAtual = 0;
uint8_t tentativas = 0;
uint8_t quantTentativas = 3;

unsigned long intervalo = 120000;         // 2 minutos por escravo
unsigned long tempoInicioTentativa = 0;
unsigned long tempoUltimaTentativa = 0;

bool aguardandoResposta = false;
bool tentativaEnviada = false;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RS485_RX, RS485_TX);
  mb.begin(&Serial2, RS485_DE_RE);
  Serial.println("ESP32 Mestre iniciado.");
}

void loop() {
  unsigned long agora = millis();

  if (!aguardandoResposta && tentativas == 0) {
    tempoInicioTentativa = agora;
    tempoUltimaTentativa = 0;
    tentativaEnviada = false;
  }

  // Se já passou tempo desde a última tentativa, e ainda dentro do intervalo
  // até quantTentativas, aí da o tempo e passa para o proximo
  if (!mb.slave() && (agora - tempoInicioTentativa < intervalo)) {
    if (!tentativaEnviada && (agora - tempoUltimaTentativa > 1000) && tentativas < quantTentativas) {
      uint8_t id = idEscravos[escravoAtual];
      tentativaEnviada = mb.readHreg(id, 0, &dadoLido, 1);
      tempoUltimaTentativa = agora;
      tentativas++;

      // mais para DEBUG agora
      if (tentativaEnviada) {
        aguardandoResposta = true;
        Serial.print("Tentativa ");
        Serial.print(tentativas);
        Serial.print(" enviada para escravo ");
        Serial.println(id);
      } else {
        Serial.println("Falha ao enviar requisição.");
      }
    }
  }

  // Quando chega a resposta
  if (mb.slave()) {
    mb.task();
  } else if (aguardandoResposta && tentativaEnviada) {
    uint8_t id = idEscravos[escravoAtual];
    Serial.print("Resposta do escravo ");
    Serial.print(id);
    Serial.print(": ");
    Serial.println(dadoLido);

    escravoAtual = (escravoAtual + 1) % NUM_ESCRAVOS;
    aguardandoResposta = false;
    tentativaEnviada = false;
    tentativas = 0;
    delay(100); // pequena pausa antes do próximo
  }

  // Se passaram os 120s e nenhuma tentativa funcionou
  if ((agora - tempoInicioTentativa >= intervalo) && tentativas >= 3 && !aguardandoResposta) {
    uint8_t id = idEscravos[escravoAtual];
    Serial.print("Nenhuma resposta do escravo ");
    Serial.println(id);

    escravoAtual = (escravoAtual + 1) % NUM_ESCRAVOS;
    tentativas = 0;
    tentativaEnviada = false;
    aguardandoResposta = false;
  }

  delay(5);
}

#include "rs485.h"

SoftwareSerial mySerial(RX, TX);
typedef uint8_t byte;

void rs485_init(){
  pinMode(RE, OUTPUT);
  digitalWrite(RE, LOW);
  mySerial.begin(115200);
}

void rs485_send_data(FILTER_MOVING_AVERAGE_PTR filterAvg)
{
#ifdef DEBUG
  Serial.println("Enviando dados acumulados via RS485...");
#endif
  digitalWrite(RE, HIGH);
  //filter_apply(&filterComp, &filterButter, filterAvg);

  byte buffer[9];
  buffer [0] = 0xFF;

  union{
    int16_t value;
    byte bytes[2];
  } data;
  
  data.value = (int16_t)(filterAvg->avg_roll* 100);
  buffer[1] = data.bytes[1];
  buffer[2] = data.bytes[0];

  data.value = (int16_t)(filterAvg->avg_pitch * 100);
  buffer[3] = data.bytes[1];
  buffer[4] = data.bytes[0];

  data.value = (int16_t)(filterAvg->avg_yaw * 100);
  buffer[5] = data.bytes[1];
  buffer[6] = data.bytes[0];

  data.value = (int16_t)(filterAvg->deviation * 100);
  buffer[7] = data.bytes[1];
  buffer[8] = data.bytes[0];

  #ifdef DEBUG
  Serial.print("Buffer enviado: ");
  for (int i = 0; i < 9; i++) {
      Serial.print(buffer[i], HEX);
      Serial.print(" ");
  }
  Serial.println();
  #endif

  mySerial.write(buffer, 9);

  mySerial.flush(); // pra liberar o buffer

  digitalWrite(RE, LOW);

  #ifdef DEBUG
    Serial.println("Dados enviados!");
  #endif
}

bool rs485_recvCommand(RS485_CONTROL_PTR rs485Control)
{
  uint8_t indexMsg = 0;
  if (mySerial.available())
  {
    //Serial.print("oie");
    while (mySerial.available()) // Verifica se há dados disponíveis na UART
    {
      rs485Control->rs485_message[indexMsg] = mySerial.read();
    
      Serial.println(rs485Control->rs485_message[indexMsg]);
      indexMsg++;
      #ifdef DEBUG
      Serial.print("Recebido RS485: ");
      //Serial.println(receivedByte, HEX);// Exibe os dados no monitor serial em formato hexadecima
      #endif
    }
    rs485Control->rs485_size = indexMsg;
    return true;
  }
  else
    return false;
}

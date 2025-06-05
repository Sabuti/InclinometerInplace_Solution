#include <Arduino.h>

// put function declarations here:
//int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int result = 2 + 3;
  Serial.println(result);
}
void loop() {
  // put your main code here, to run repeatedly:
}
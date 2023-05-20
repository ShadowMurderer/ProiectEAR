#include "SensorFunctions.h"
#include <CAN.h>

#define TX_GPIO_NUM 2
#define RX_GPIO_NUM 1

void setup() {
  Serial.begin(115200);
  Serial.println ("Starting CAN failed");
//  SensorSetup();

  CAN.setPins (RX_GPIO_NUM, TX_GPIO_NUM);

  if (!CAN.begin (500E3)) {
    Serial.println ("Starting CAN failed");
    while(1);
  }
  else {
    Serial.println ("CAN Initialised");
  }
}

void loop() {
  delay(2000);
//  SensorLoop();
  canSender();
}

void canSender() {
  Serial.print ("Sending packet...");

  CAN.beginPacket (0x12);

  CAN.write ('1');
  CAN.write ('2');
  CAN.write ('3');
  CAN.write ('4');
  CAN.write ('5');
  CAN.write ('6');
  CAN.write ('7');
  CAN.write ('8');
  CAN.endPacket();
  
  CAN.beginPacket (0x12, 3, true);
  CAN.endPacket();
}

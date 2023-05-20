#include "DisplayFunctions.h"
#include <CAN.h>

#define TX_GPIO_NUM 1
#define RX_GPIO_NUM 3

void setup() {
  Serial.begin(115200);
//  LCDSetup();

  Serial.println ("Starting CAN 87t86td");
  CAN.setPins(13, 12);
  Serial.println ("Starting CAN 1231236td");
//
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
//  LCDLoop();

  canReceiver();
}

void canReceiver() {
  // try to parse packet
  Serial.println("CAN function here hehehehe");
  int packetSize = CAN.parsePacket();

  if (packetSize) {
    // received a packet
    Serial.print ("Received ");

    if (CAN.packetExtended()) {
      Serial.print ("extended ");
    }

    if (CAN.packetRtr()) {
      // Remote transmission request, packet contains no data
      Serial.print ("RTR ");
    }

    Serial.print ("packet with id 0x");
    Serial.print (CAN.packetId(), HEX);

    if (CAN.packetRtr()) {
      Serial.print (" and requested length ");
      Serial.println (CAN.packetDlc());
    } else {
      Serial.print (" and length ");
      Serial.println (packetSize);

      // only print packet data for non-RTR packets
      while (CAN.available()) {
        Serial.print ((char) CAN.read());
      }
      Serial.println();
    }

    Serial.println();
  }
}

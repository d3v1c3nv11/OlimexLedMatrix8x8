#include <SPI.h>
#include "LedMatrix.h"


#define NUMBER_OF_DEVICES 1
#define CS_PIN 5

LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, CS_PIN);

void setup() {
  ledMatrix.init();
  ledMatrix.setText("Testing Olimex LED 8x8 ");
  }

void loop() {

  ledMatrix.clear();
  ledMatrix.scrollTextLeft();
  ledMatrix.drawText();
  for (byte i = 0; i < 30; i++){
  ledMatrix.commit();
  delay(2);}

}

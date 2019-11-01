#include <SPI.h>
#include "LedMatrix.h"

#define NUMBER_OF_DEVICES 1
#define CS_PIN 5

LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, CS_PIN);
int x = 0;

void ICACHE_RAM_ATTR onTimerISR(){
timer1_write(10000); //2000 us
x++;
if (x>30){
x=0;
  ledMatrix.clear();
  ledMatrix.scrollTextLeft();
  ledMatrix.drawText();
  ESP.wdtFeed();
}
ledMatrix.commit();

}

void setup() {
  Serial.begin(74600);
  ledMatrix.init();
  ledMatrix.setText("Testing Olimex LED 8x8 ");
  //
  timer1_attachInterrupt(onTimerISR);
  timer1_enable(TIM_DIV16, TIM_EDGE, TIM_SINGLE);
  timer1_write(10000); //2000 us
  }

void loop() {


}

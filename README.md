# OlimexLedMatrix8x8
Library for the ESP8266 on Arduino IDE displaying text on the Olimex BADGE-ESP8266-Led8x8

This library displays text and sets specific pixels on one or multiple 8x8 led matrices with a Olimex MOD-LED8x8 & ESP8266-evb controlled through the SPI interface.
These modules are relatively cheep and can be daisy chained which makes it easy to get a led text bar up and running
You can find modules e.g. with [Olimex] will be updated later...

Currently this library supports the following operations:

- set pixels
- write text with a simple font
- scroll text left or right
- oscillate text between the two ends

## Example

```
#include <SPI.h>
#include "LedMatrix.h"


#define NUMBER_OF_DEVICES 1
#define CS_PIN 5
#define DATA_PIN 13
#define CLOCK_PIN 14

LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, DATA_PIN, CLOCK_PIN, CS_PIN);

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
```
## Installing library in Arduino IDE
- open Arduino IDE
- open preferences and take note of the 'Sketchbook location' path
- navigate into the `libraries` sub folder at that path (e.g. with terminal)
- clone this Git repository into that folder
- restart Arduino IDE
- you should now find the OlimexLedMatrix8x8 library in Sketch > Include Library

## Connecting the module(s) to the ESP8266

|LED Matrix |	ESP8266                     |
|-----------|-----------------------------|
|VCC        |	+3.3V                       |
|GND	      | GND                         |
|DIN	      |GPIO13 (HSPID)               |
|CS	        |Choose free GPIO, e.g. GPIO5 |
|CLK	      |GPIO14 (HSPICLK)             |

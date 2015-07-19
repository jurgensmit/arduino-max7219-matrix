/*
 * Arduino MAX7219 LED Matrix - Connect an 8 x 8 LED Matrix to an Arduino
 *
 * Connect a 8 x 8 LED Maxtrix to an Arduino and have some fun with it. Can be used to indicate
 * something has happened, for instance a new mail has been received.
 *
 * (c) 2015 Jurgen Smit. All rights reserved.
 *
 * Circuit: 
 *
 * - LED Matrix 8*8 with MAX7219 Module, connected to pin 2 (DIN), pin 3 (CS) and pin 4 (CLK)
 *        http://www.tinytronics.nl/shop/LED-Matrix-8*8-with-MAX7219-Module
 *
 * External References:
 *
 * - Arduino MaxMatrix Library: https://code.google.com/p/arudino-maxmatrix-library/
 *
 */

#include <MaxMatrix.h>
#include <SoftwareSerial.h>

#define DATA_PIN 2    // DIN pin of MAX7219 module
#define LOAD_PIN 3    // CS pin of MAX7219 module
#define CLOCK_PIN 4   // CLK pin of MAX7219 module
#define ON 1          // Pixel on
#define OFF 0         // Pixel off
#define INTENSITY 7   // The intensity of the LEDs, 0 to 15

MaxMatrix matrix(DATA_PIN, LOAD_PIN, CLOCK_PIN, 1);

const byte smiley_up[] = {
  8, 8,       // Width, length
  B00111100,  // First column
  B01000010,
  B10101001,
  B10000101,
  B10000101,
  B10101001,
  B01000010,
  B00111100   // Last column
};

const byte smiley_down[] = {
  8, 8,       // Width, length
  B00111100,  // First column
  B01000010,
  B10100011,
  B10000101,
  B10000101,
  B10100011,
  B01000010,
  B00111100   // Last column
};

void setup() {
  matrix.init(); 
  matrix.setIntensity(INTENSITY); 
}

void loop() {
  matrix.writeSprite(0, 0, smiley_up);
  delay(500);
  matrix.writeSprite(0, 0, smiley_down);
  delay(500);
}

#include "FastLED.h"

#define delayms 2000

#define LEDS_STRIP_UNDER_LEFT 60
#define LEDS_STRIP_UNDER_RIGHT 60
#define LEDS_STRIP_UPPER_LEFT 60
#define LEDS_STRIP_UPPER_RIGHT 60
#define LEDS_EXTRA_ONE 60
#define LEDS_EXTRA_TWO 60

#define DATA_PIN_STRIP_UNDER_LEFT 2
#define DATA_PIN_STRIP_UNDER_RIGHT 3
#define DATA_PIN_STRIP_UPPER_LEFT 4
#define DATA_PIN_STRIP_UPPER_RIGHT 5
#define DATA_PIN_EXTRA_ONE 6
#define DATA_PIN_EXTRA_TWO 7

#define SWITCH_PIN_BLUE 12
#define SWITCH_PIN_RED 11

CRGB ledsUnderLeft[LEDS_STRIP_UNDER_LEFT];
CRGB ledsUnderRight[LEDS_STRIP_UNDER_RIGHT];
CRGB ledsUpperLeft[LEDS_STRIP_UPPER_LEFT];
CRGB ledsUpperRight[LEDS_STRIP_UPPER_RIGHT];
CRGB ledsExtraOne[LEDS_EXTRA_ONE];
CRGB ledsExtraTwo[LEDS_EXTRA_TWO];


void setup() {
 pinMode(SWITCH_PIN_BLUE, INPUT);
 pinMode(SWITCH_PIN_RED, INPUT);
 //Serial.begin(9600);
 FastLED.addLeds<NEOPIXEL, DATA_PIN_STRIP_UNDER_LEFT>(ledsUnderLeft, LEDS_STRIP_UNDER_LEFT);
 FastLED.addLeds<NEOPIXEL, DATA_PIN_STRIP_UNDER_RIGHT>(ledsUnderRight, LEDS_STRIP_UNDER_RIGHT);
 FastLED.addLeds<NEOPIXEL, DATA_PIN_STRIP_UPPER_LEFT>(ledsUpperLeft, LEDS_STRIP_UPPER_LEFT);
 FastLED.addLeds<NEOPIXEL, DATA_PIN_STRIP_UPPER_RIGHT>(ledsUpperRight, LEDS_STRIP_UPPER_RIGHT);
 FastLED.addLeds<NEOPIXEL, DATA_PIN_EXTRA_ONE>(ledsExtraOne, LEDS_EXTRA_ONE);
 FastLED.addLeds<NEOPIXEL, DATA_PIN_EXTRA_TWO>(ledsExtraTwo, LEDS_EXTRA_TWO);

}

void turnRed( CRGB *strip, uint8_t pixels) {
  ////Serial.println("begin turnRed");
  for (uint8_t i = 0; i < pixels; ++i){
     strip[i] = CRGB::Red;  
     //Serial.print(i);
     //Serial.print(":");
     //Serial.println(strip[i]);
  }
}

void turnBlue( CRGB *strip, uint8_t pixels) {
  //Serial.println("begin turnBlue");
  for (uint8_t i = 0; i < pixels; ++i){
     strip[i] = CRGB::Blue;  
     //Serial.print(i);
     //Serial.print(":");
     //Serial.println(strip[i]);
  }
}

void turnBlack( CRGB *strip, uint8_t pixels) {
  //Serial.println("begin turnBlack");
  for (uint8_t i = 0; i < pixels; ++i){
     strip[i] = CRGB::Black;  
     //Serial.print(i);
     //Serial.print(":");
     //Serial.println(strip[i]);
  }
}

void allBlue() {
  turnBlue(ledsUnderLeft, LEDS_STRIP_UNDER_LEFT);
  turnBlue(ledsUnderRight, LEDS_STRIP_UNDER_RIGHT);
  turnBlue(ledsUpperLeft, LEDS_STRIP_UPPER_LEFT);
  turnBlue(ledsUpperRight, LEDS_STRIP_UPPER_RIGHT);
  turnBlue(ledsExtraOne, LEDS_EXTRA_ONE);
  turnBlue(ledsExtraTwo, LEDS_EXTRA_TWO);
  
}

void allRed() {
  turnRed(ledsUnderLeft, LEDS_STRIP_UNDER_LEFT);
  turnRed(ledsUnderRight, LEDS_STRIP_UNDER_RIGHT);
  turnRed(ledsUpperLeft, LEDS_STRIP_UPPER_LEFT);
  turnRed(ledsUpperRight, LEDS_STRIP_UPPER_RIGHT);
  turnRed(ledsExtraOne, LEDS_EXTRA_ONE);
  turnRed(ledsExtraTwo, LEDS_EXTRA_TWO);
}  

void allBlack() {
  turnBlack(ledsUnderLeft, LEDS_STRIP_UNDER_LEFT);
  turnBlack(ledsUnderRight, LEDS_STRIP_UNDER_RIGHT);
  turnBlack(ledsUpperLeft, LEDS_STRIP_UPPER_LEFT);
  turnBlack(ledsUpperRight, LEDS_STRIP_UPPER_RIGHT);
  turnBlack(ledsExtraOne, LEDS_EXTRA_ONE);
  turnBlack(ledsExtraTwo, LEDS_EXTRA_TWO);   
}

void loop() {
  //Serial.println();

  if(digitalRead(SWITCH_PIN_BLUE) == HIGH) {
    allBlue();
  }
  if(digitalRead(SWITCH_PIN_RED) == HIGH) {
    allRed();  
  }
  if(digitalRead(SWITCH_PIN_BLUE) == LOW && digitalRead(SWITCH_PIN_RED) == LOW) {
    allBlack();
  }
  FastLED.show();
}

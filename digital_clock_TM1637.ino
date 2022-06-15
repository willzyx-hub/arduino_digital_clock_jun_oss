// No copyright files
#include <Wire.h>
#include <RTClib.h>
#include "SevenSegmentTM1637.h"

const byte PIN_CLK = 5;
const byte PIN_DIO = 6;
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);
RTC_DS3231 rtc;


void setup() {
  //Serial.begin(9600);
  display.begin();
  display.setBacklight(100);
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  display.print("ALIM");
  delay(1000);

}

void loop() {
  DateTime now = rtc.now();

  if (now.hour() < 10) {
    display.setCursor(0, 0); display.print("0");
    display.setCursor(0, 1); display.print(now.hour());
  }
  else {
    display.setCursor(0, 0); display.print(now.hour());
  }

  if (now.minute() < 10) {
    display.setCursor(0, 2); display.print("0");
    display.setCursor(0, 3); display.print(now.minute());
  }
  else {
    display.setCursor(0, 2); display.print(now.minute());
  }

  if (now.second() % 2 == 0) {
    display.setColonOn(1);
    Serial.print(now.hour());
    Serial.print(now.minute());
  }
  else {
    display.setColonOn(0);
  }

}

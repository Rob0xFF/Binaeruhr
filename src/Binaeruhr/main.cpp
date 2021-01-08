#include <Arduino.h>
#include <Wire.h>

#include "board.h"

#define DS3231_INT_PIN 3
#define DS3231_INT 1

Board * board;

volatile uint8_t tick = true;
#define TOCK false;
void tickTock()
{
  tick = true;
}

int atexit(void ( * /*func*/ )())
{
  return 0;
}

void initVariant() __attribute__((weak));
void initVariant() { }

int main(void)
{
  init();
  initVariant();
  Serial.begin(115200);
  board = new Board();
  // interrupt on external 1Hz clock signal
  pinMode(DS3231_INT_PIN, INPUT_PULLUP);
  attachInterrupt(DS3231_INT, tickTock, FALLING);
  for (;;) {
    if (tick) {
      board -> update();
      tick = TOCK;
    }
  }
  return 0;
}
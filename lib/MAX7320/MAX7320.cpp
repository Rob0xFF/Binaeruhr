#include <MAX7320.h>

void MAX7320::setOutput(uint8_t val)
{
  Wire.beginTransmission(_addr);
  Wire.write(val);
  Wire.endTransmission();
}

uint8_t MAX7320::getOutput(void)
{
  uint8_t data = 0;
  Wire.beginTransmission(_addr);
  Wire.requestFrom(_addr, (uint8_t) 1);
  while (Wire.available())	{
    data = Wire.read();
  }
  return data;
}
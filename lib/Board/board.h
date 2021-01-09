#ifndef BOARD_h
#define BOARD_h

#include "Arduino.h"
#include "Wire.h"

#include <DS3231.h>
#include <MAX7320.h>

class Board
{
  public:

    Board()
    {
      _clock.begin();
      // uncomment to automatically set clock, you need to comment, recompile and flash again after the clock is set and running, otherwise the clock will be set to this date everytime the device is started
      //_clock.setDateTime(__DATE__, __TIME__);
      _clock.setOutput(DS3231_1HZ);
      _clock.enableOutput(true);
      _binaryHours.setOutput(0xFF);
      _binaryMinutes.setOutput(0xFF);
      _binarySeconds.setOutput(0xFF);
    };

    void update(void);

  private:

    DS3231 _clock;
    RTCDateTime _dt;

    inline void updateTime()
    {
      _dt = _clock.getDateTime();
    };

    MAX7320 _binaryHours = MAX7320(0x58);

    MAX7320 _binaryMinutes = MAX7320(0x59);

    MAX7320 _binarySeconds = MAX7320(0x5D);

};
#endif
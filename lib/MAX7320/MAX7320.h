#ifndef MAX7320_h
#define MAX7320_h

#include "Arduino.h"
#include "Wire.h"

/*!
 * @brief MAX7320 main class
 */
class MAX7320
{
  public:

    MAX7320(uint8_t addr) : _addr(addr) 
		{
		};

		void setOutput(uint8_t val);

		uint8_t getOutput(void);

  private:

		uint8_t _addr;

};
#endif
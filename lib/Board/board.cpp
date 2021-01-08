#include <board.h>

void Board::update(void)
{
	updateTime();
	_binaryHours.setOutput(~(((_dt.hour / 10) << 4) | ((_dt.hour % 10) & 0b00001111)));
	_binaryMinutes.setOutput(~(((_dt.minute / 10) << 4) | ((_dt.minute % 10) & 0b00001111)));
	_binarySeconds.setOutput(~(((_dt.second / 10) << 4) | ((_dt.second % 10) & 0b00001111)));
}
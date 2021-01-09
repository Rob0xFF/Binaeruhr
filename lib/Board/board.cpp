#include <board.h>

void Board::update(void)
{
	updateTime();
	_binaryHours.setOutput(~((((_dt.hour / 10) << 4) & 0x30) | ((_dt.hour % 10) & 0x0F)));
	_binaryMinutes.setOutput(~((((_dt.minute / 10) << 4) & 0x70) | ((_dt.minute % 10) & 0x0F)));
	_binarySeconds.setOutput(~((((_dt.second / 10) << 4) & 0x70) | ((_dt.second % 10) & 0x0F)));
}
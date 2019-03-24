#ifndef AC4790_h
#define AC4790_h

#include "Arduino.h"

class AC4790
{

	public:
	
		byte* enterCmdMode(byte[]);

		byte* getFirmwareVersion(byte[]);
	
		byte* readTemp(byte[]);
	
		byte* setMaxPower(byte[],byte[]);
	
		byte* EEPROMRead(byte[],byte[],byte[]);

		byte* EEPROMWrite(byte[],byte[],byte[],byte[]);
};
#endif

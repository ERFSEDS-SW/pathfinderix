#ifndef AC4790_h
#define AC4790_h

#include "Arduino.h"

class AC4790
{

	public:
	
		byte* enterCmdMode(byte[]);

		byte* getFirmwareVersion(byte[]);
	
		byte* readTemp(byte[]);
	
		byte* setMaxPower(byte[],int newPower);
	
		byte* EEPROMRead(byte[],int,int);

		byte* EEPROMWrite(byte[],int,int,int);
};
#endif

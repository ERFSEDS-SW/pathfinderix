#ifndef AC4790_h
#define AC4790_h

#include "Arduino.h"

class AC4790
{

public:
	
	byte* enterCmdMode(byte[]);

	byte* getFirmwareVersion(byte[]);

};
#endif

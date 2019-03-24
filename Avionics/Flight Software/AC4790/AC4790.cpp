//IMPORTANT: This sketch was designed to work with Arduino MEGA, will not work on an Uno
#include "Arduino.h"
#include "AC4790.h"
//--------------------



//AC4790::AC4790(void){}



byte* AC4790::enterCmdMode(byte confirmCmd[])
{
  byte enterCmd[6] = {0x41, 0x54, 0x2B, 0x2B, 0x2B, 0x0D};
  byte returnCmd;
  //byte confirmCmd[4];
  //-----------------
  Serial.begin(9600); //read/write to/from computer
  Serial3.begin(9600); //read/write to/from transceiver
  //Allow transceiver to take commands
  Serial3.write(enterCmd, 6);
  //Print returned bytes to ensure that it is working
  delay(100);
  if(Serial3.available()>0){
    returnCmd = Serial3.readBytes(confirmCmd,4);
    for(int i=0; i<=3; i++){
      Serial.println(confirmCmd[i]);
    }
  }
  Serial.println("SETUP COMPLETE");
  return confirmCmd;
}

//--------------------

//--------------------------

byte* AC4790::getFirmwareVersion(byte dataRec[])
{
  byte statusReq[3] = {0xCC, 0x00, 0x00};
  //byte dataRec[3];
  byte incomingBytes;
  int firmVers;   
  //-----------------------   
     //Send Status Request command
  Serial3.write(statusReq, 3);
  delay(500);
  //Read returned bytes from transceiver
  if(Serial3.available()>0)
	{
		incomingBytes = Serial3.readBytes(dataRec,3);
		//Find and display returned firmware version
		for( int i = 0; i<3; i++)
			{
			if (i == 1){
				Serial.print("Firmware Version: ");
			}	
			Serial.println(dataRec[i]);
			
			}
		delay(500);
	}
	return dataRec;
}


//--------------------------

byte* AC4790::readTemp(byte dataTemp[])
{
	byte tempByte[2] = {0xCC, 0xA4};
	byte tempReadBytes;
	//-----------------
	Serial3.write(tempByte, 2);
	delay(500);
	//Read returned bytes from transceiver
	if(Serial3.available()>0){
		tempReadBytes = Serial3.readBytes(dataTemp,2);
		//Find and display returned firmware version
		for( int i = 0; i<2; i++)
		{
			if (i == 1){
				Serial.print("Temperature (°C): ");
			}
			Serial.println(dataTemp[i]);
		}
		delay(500);
    }
    return dataTemp;
}


//----------------------------
byte* AC4790::setMaxPower(byte confirmPwr[],byte newPower[])
{
	byte powerByte[3] = {0xCC,0x25,newPower};
	byte returnPwr;
	//-------------
	Serial3.write(powerByte, 3);
	delay(500);
	//Read returned bytes
	if(Serial3.available()>0)
	{
		returnPwr = Serial3.readBytes(confirmPwr,2);
		for(int i = 0; i<2; i++)
		{
			if(i == 1){
				Serial.print("Max. Power: ");
			}
			Serial.println(confirmPwr[i]);
		}
		delay(500);
	}
	return confirmPwr;
}

//----------------------------

byte* AC4790::EEPROMRead(byte confirmRead[],byte StartAddressRead[],byte LengthRead[])
{
	byte readCmd[4] = {0xCC,0xC0,StartAddressRead,LengthRead};
	byte returnRead;
	//--------------
	Serial3.write(readCmd, 4);
	delay(500);
	//Read returned Bytes
	if(Serial3.available()>0)
	{
		returnRead = Serial3.readBytes(confirmRead,4);
		for(int i = 0; i<4; i++)
		{
			if(i == 1){
				Serial.print("Starting Address: ");
			}
			else if(i == 2){
				Serial.print("Length: ");
			}
			else if(i == 3){
				Serial.print("Data: ");
			}
			Serial.println(confirmRead[i]);
		}
		delay(500);
	}
	return confirmRead;
}

//------------------------------------------

byte* AC4790::EEPROMWrite(byte confirmWrite[],byte StartAddressWrite[],byte LengthWrite[],byte WriteData[])
{
	byte WriteCmd[5] = {0xCC,0xC1,StartAddressWrite,LengthWrite,WriteData};
	byte returnWrite;
	//--------------
	Serial3.write(WriteCmd, 5);
	delay(500);
	//Read returned Bytes
	if(Serial3.available()>0)
	{
		returnWrite = Serial3.readBytes(confirmWrite,3);
		for(int i = 0; i<3; i++)
		{
			if(i == 0){
				Serial.print("Starting Address: ");
			}
			else if(i == 1){
				Serial.print("Length: ");
			}
			else if(i == 2){
				Serial.print("Data Written: ");
			}
			Serial.println(confirmWrite[i]);
		}
		delay(500);
	}
	return confirmWrite;
}

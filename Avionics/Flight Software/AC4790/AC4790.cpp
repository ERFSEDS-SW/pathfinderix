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
  if(Serial3.available()>0){
    incomingBytes = Serial3.readBytes(dataRec,3);
    //Find and display returned firmware version
    for( int i = 0; i<3; i++)
    {
      Serial.println(dataRec[i]);
    }
    delay(500);
    }
    return dataRec;
}


//--------------------------

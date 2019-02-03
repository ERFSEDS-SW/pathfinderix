#include <AC4790.h>

AC4790 transceiver;

void setup() {
  // put your setup code here, to run once:
  byte cmdBytesOut[4];
  transceiver.enterCmdMode(cmdBytesOut);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte firmwareBytesOut[3];
  transceiver.getFirmwareVersion(firmwareBytesOut);

  //test temperature read
  byte tempBytesOut[2];
  transceiver.readTemp(tempBytesOut);

  //test set new max power
  byte powerBytesOut[3];
  int newPower;
  transceiver.setMaxPower(powerBytesOut,newPower);

  //test EEPROMRead
  byte ReadEEPROMBytes[4];
  int StartAddressRead; 
  int LengthRead;
  transceiver.EEPROMRead(ReadEEPROMBytes,StartAddressRead,LengthRead);
  
  //test EEPROMWrite
  byte WriteEEPROMBytes[5];
  int StartAddressWrite;
  int LengthWrite;
  int WriteData;
  transceiver.EEPROMWrite(WriteEEPROMBytes,StartAddressWrite,LengthWrite,WriteData);

  //test EEPROMRead again after written data input
  transceiver.EEPROMRead(ReadEEPROMBytes,StartAddressRead,LengthRead);
  
}

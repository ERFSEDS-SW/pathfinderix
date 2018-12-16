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
}

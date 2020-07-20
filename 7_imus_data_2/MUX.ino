#include <Wire.h>
#define TCAADDR 0x70
void tcaselect(uint8_t channel) {
  if (channel > 7) return;
  //Serial.print("I2C Channel: ");  Serial.println(channel);
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << channel);
  Wire.endTransmission(); 
}

#include <Wire.h>
#define TCAADDR 0x70
/* Function: TcaSelect
 *  Base method to  change between I2C channels with TCA MUX
 * 
 * Parameters:
 *  channel(uint8_t) - Channel to obtain the data
 *  
 * Returns:
 */
void TcaSelect(uint8_t channel)
{
  if (channel > 7) return;
  //Serial.print("I2C Channel: ");  Serial.println(channel);
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << channel);
  Wire.endTransmission(); 
}

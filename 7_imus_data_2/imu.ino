#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

// Create bno variable
Adafruit_BNO055 bno = Adafruit_BNO055(-1);

// Check I2C device address and correct line below (by default address is 0x29 or 0x28)
//                                  id, address
/*
 * lumbar=0
 * right=1
 * left=2
 * right foot=3
 * left foot =4
 */
void SetUpIMUs(int ch,
               int pos)
{
  /* Initialise the sensor */
  tcaselect(ch);
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    Serial.print(ch);
    while(1);
  }

  delay(100);
  switch(pos){
    case 0:
    bno.setAxisRemap(Adafruit_BNO055::REMAP_CONFIG_P0);// modify
    bno.setAxisSign(Adafruit_BNO055::REMAP_SIGN_P3);// modify
    bno.setExtCrystalUse(true);

    case 1:
    bno.setAxisRemap(Adafruit_BNO055::REMAP_CONFIG_P0);// modify
    bno.setAxisSign(Adafruit_BNO055::REMAP_SIGN_P3);// modify
    bno.setExtCrystalUse(true);

    case 2: 
    bno.setAxisRemap(Adafruit_BNO055::REMAP_CONFIG_P0);// modify
    bno.setAxisSign(Adafruit_BNO055::REMAP_SIGN_P3);// modify
    bno.setExtCrystalUse(true);

    case 3:
    bno.setAxisRemap(Adafruit_BNO055::REMAP_CONFIG_P0);// modify
    bno.setAxisSign(Adafruit_BNO055::REMAP_SIGN_P3);
    bno.setExtCrystalUse(true);

    case 4:
    bno.setAxisRemap(Adafruit_BNO055::REMAP_CONFIG_P0);// modify
    bno.setAxisSign(Adafruit_BNO055::REMAP_SIGN_P3);// modify
    bno.setExtCrystalUse(true);
  }
  


    
}
/*
 * WIth the MUX channel and the position
 */

data_vector ReadIMU(int ch, data_vector vector){
  tcaselect(ch); // change I2C channel
  sensors_event_t event; // create event variable
  bno.getEvent(&event);
  vector.euler=event.orientation.y;
  vector.gyro=event.gyro.z;
  imu::Quaternion quat=bno.getQuat();
  vector.qx=quat.x();
  vector.qy=quat.y();
  vector.qz=quat.z();
  vector.qw=quat.w();
  return vector;
}

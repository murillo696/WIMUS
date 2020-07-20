#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#define TCAADDR 0x70
#define N_IMUS 7
#define R_THIGH_MUX 0
#define R_SHANK_MUX 1
#define R_FOOT_MUX 2
#define L_THIGH_MUX 3
#define L_SHANK_MUX 4
#define L_FOOT_MUX 5
#define LUMBAR_MUX 6

/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS 10


typedef struct data_vector{
  double euler;
  double gyro;
  double qx;
  double qy;
  double qz;
  double qw;
};

/*Adjust the running frequency to the Teensy's frequency*/
#if defined(__IMXRT1062__)
extern "C" uint32_t set_arm_clock(uint32_t frequency);
#endif

//init variables array
data_vector lumbar;
data_vector r_thigh;
data_vector r_shank;
data_vector r_foot;
data_vector l_thigh;
data_vector l_shank;
data_vector l_foot;
void setup(void){
  #if defined(__IMXRT1062__)
    set_arm_clock(600000000); // frequency of the Teensy
  #endif
  Serial.begin(115200);
  Wire.begin();
  
  SetUpIMUs(LUMBAR_MUX,
            0);
            
  SetUpIMUs(R_THIGH_MUX,
            1);
            
  SetUpIMUs(R_SHANK_MUX,
            1);
            
  SetUpIMUs(R_FOOT_MUX,
            3);
            
  SetUpIMUs(L_THIGH_MUX,
            2);
            
  SetUpIMUs(L_SHANK_MUX,
            2);
            
  SetUpIMUs(L_FOOT_MUX,
            4);
}

void loop(void){
  // get lumbar data
  lumbar=ReadIMU(LUMBAR_MUX,
                 lumbar);
  
 // get lumbar data  
  r_thigh=ReadIMU(R_THIGH_MUX,
                  r_thigh);

  // get lumbar data
  r_shank=ReadIMU(R_SHANK_MUX,
                  r_shank);

  // get lumbar data
  r_foot=ReadIMU(R_FOOT_MUX,
                 r_foot);
    
  // get lumbar data
  l_thigh=ReadIMU(L_THIGH_MUX,
                  l_thigh);

  // get lumbar data  
  l_shank=ReadIMU(L_SHANK_MUX,
                  l_shank);

  // get lumbar data
  l_foot=ReadIMU(L_FOOT_MUX,
                 l_foot);
                 
  //Send Telemetry
  TelemetrySend(42,
                lumbar,
                r_thigh,
                r_shank,
                r_foot,
                l_thigh,
                l_shank,
                l_foot);
}

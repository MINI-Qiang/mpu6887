#include "mpu6887.h"
mpu6887 mpu;
void setup()
{
  mpu.begin();
  mpu.ACCEL_SCOPE_CONFIG(Accel_2G);
  Serial.begin(115200);
}

void loop()
{
  int acc_x = mpu.ACCEL_X();
  int acc_y = mpu.ACCEL_Y();
  int acc_z = mpu.ACCEL_Z();
  
  uint16_t adc_x = map(acc_x,-32768,32767,0,1024);
  uint16_t adc_y = map(acc_y,-32768,32767,0,1024);
  uint16_t adc_z = map(acc_z,-32768,32767,0,1024);
  Serial.print(adc_x);
  Serial.print(",");
  Serial.print(adc_y);
  Serial.print(",");
  Serial.println(adc_z);
}
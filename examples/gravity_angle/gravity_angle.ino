#include "mpu6887.h"
#include <math.h>


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

  float ax = acc_x * 2.0 / 32768.0;
  float ay = acc_y * 2.0 / 32768.0;
  float az = acc_z * 2.0 / 32768.0;

  float theta_x = atan(ax / sqrt(ay*ay + az*az)) * 180 / PI;
  float theta_y = atan(ay / sqrt(ax*ax + az*az)) * 180 / PI;
  
  Serial.print(theta_x);
  Serial.print(",");
  Serial.println(theta_y);
}
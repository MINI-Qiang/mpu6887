# include "mpu6887.h"

mpu6887 mpu;
void setup()
{
  mpu.begin();
  mpu.ACCEL_SCOPE_CONFIG(Accel_2G);
  Serial.begin(115200);
}

void loop()
{
  Serial.print(mpu.ACCEL_X_g());
  Serial.print(",");
  Serial.print(mpu.ACCEL_Y_g());
  Serial.print(",");
  Serial.println(mpu.ACCEL_Z_g());
  delay(10);
}
# include "mpu6887.h"

mpu6887 mpu;
void setup()
{
  mpu.begin();
  //mpu.GYRO_SCOPE_CONFIG(Gyro_2000dps);
  mpu.ACCEL_SCOPE_CONFIG(Accel_16G);
  Serial.begin(115200);

}

void loop()
{

  Serial.print(mpu.ACCEL_X());
  Serial.print(",");
  Serial.print(mpu.ACCEL_Y());
  Serial.print(",");
  Serial.println(mpu.ACCEL_Z());

  //Serial.println(mpu.TEMP());
  /*
    Serial.print(mpu.GYRO_X());
    Serial.print(",");
    Serial.print(mpu.GYRO_Y());
    Serial.print(",");
    Serial.println(mpu.GYRO_Z());
  */
  delay(10);
}
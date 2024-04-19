# include "mpu6887.h"
mpu6887 mpu;
void setup()
{
  mpu.begin();
  mpu.GYRO_SCOPE_CONFIG(Gyro_250dps);
  Serial.begin(115200);

}

void loop()
{
    Serial.print(mpu.GYRO_X_dps());
    Serial.print(",");
    Serial.print(mpu.GYRO_Y_dps());
    Serial.print(",");
    Serial.println(mpu.GYRO_Z_dps());
    delay(10);
}
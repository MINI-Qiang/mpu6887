#include "mpu6887.h"
mpu6887 mpu;
void setup()
{
  mpu.begin();
  Serial.begin(115200);
}

void loop()
{
  Serial.println(mpu.temperature());
  delay(10);
}
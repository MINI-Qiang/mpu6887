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

  float ax = acc_x / 32768.0 * 2; // 将加速度计数据规范化到+-2G
  float ay = acc_y / 32768.0 * 2;
  float az = acc_z / 32768.0 * 2;

  float pitch = atan2(-ay, az) * (180.0 / M_PI);
  float roll = atan2(ax, sqrt(ay * ay + az * az)) * (180.0 / M_PI);

  Serial.print(pitch);  //俯仰 绕X轴旋转,单位度
  Serial.print(",");
  Serial.println(roll);   //横滚 绕Y轴旋转 单位度
}
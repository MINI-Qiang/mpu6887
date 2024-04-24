#include "mpu6887.h"
#include <math.h>
mpu6887 mpu;

float yaw = 0.0; // 偏航角初始化为0
unsigned long lastTime = 0; // 上一次更新时间
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

  int gyro_z = mpu.GYRO_Z_dps(); // 获取陀螺仪Z轴的度每秒值
  unsigned long currentTime = millis();
  float deltaTime = (currentTime - lastTime) / 1000.0; // 时间差，单位为秒

  yaw += gyro_z * deltaTime; // 累加计算偏航角
  lastTime = currentTime; // 更新时间戳
  float ax = acc_x / 32768.0 * 2; // 将加速度计数据规范化到+-2G
  float ay = acc_y / 32768.0 * 2;
  float az = acc_z / 32768.0 * 2;

  float pitch = atan2(-ay, az) * (180.0 / M_PI);
  float roll = atan2(ax, sqrt(ay * ay + az * az)) * (180.0 / M_PI);

  if (yaw > 360) {
    yaw -= 360;
  } else if (yaw < 0) {
    yaw += 360;
  }
  Serial.print(pitch);  //俯仰 绕X轴旋转,单位度
  Serial.print(",");
  Serial.print(roll);   //横滚 绕Y轴旋转 单位度
  Serial.print(",");
  Serial.println(yaw);  //偏航 绕Z轴旋转 单位度
}
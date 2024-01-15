#include "mpu6887.h"

mpu6887::mpu6887()
{
}

void mpu6887::begin()
{
    Wire.setSDA(12); // Set the SDA pin, if necessary for your board
    Wire.setSCL(13); // Set the SCL pin, if necessary for your board
    Wire.begin();    // Start the I2C Bus

    //关闭芯片休眠,启动传感器
    writeBytes(PWR_MGMT_1, 0x00, 1);
}

int16_t mpu6887::ACCEL_X()
{
    uint8_t buf[2];
    readBytes(ACCEL_XOUT_H, buf, 2);
    return (((int16_t)buf[0]) << 8) | buf[1];
}

int16_t mpu6887::ACCEL_Y()
{
    uint8_t buf[2];
    readBytes(ACCEL_YOUT_H, buf, 2);
    return (((int16_t)buf[0]) << 8) | buf[1];
}

int16_t mpu6887::ACCEL_Z()
{
    uint8_t buf[2];
    readBytes(ACCEL_ZOUT_H, buf, 2);
    return (((int16_t)buf[0]) << 8) | buf[1];
}

int16_t mpu6887::GYRO_X()
{
    uint8_t buf[2];
    readBytes(GYRO_XOUT_H, buf, 2);
    return (((int16_t)buf[0]) << 8) | buf[1];
}

int16_t mpu6887::GYRO_Y()
{
    uint8_t buf[2];
    readBytes(GYRO_YOUT_H, buf, 2);
    return (((int16_t)buf[0]) << 8) | buf[1];
}

int16_t mpu6887::GYRO_Z()
{
    uint8_t buf[2];
    readBytes(GYRO_ZOUT_H, buf, 2);
    return (((int16_t)buf[0]) << 8) | buf[1];
}

int16_t mpu6887::TEMP()
{
    uint8_t buf[2];
    readBytes(TEMP_OUT_H, buf, 2);
    return (((int16_t)buf[0]) << 8) | buf[1];
}

void mpu6887::readBytes(uint8_t reg, uint8_t *buf, uint8_t len)
{
    // 发送读取寄存器地址
    Wire.beginTransmission(MPU6887_ADDRESS);
    Wire.write(reg);
    Wire.endTransmission(false);
    // 读取数据
    Wire.requestFrom(MPU6887_ADDRESS, len, true);
    while (Wire.available() < len)
        ;
    for (int i = 0; i < len; i++)
    {
        buf[i] = Wire.read();
    }
}

void mpu6887::writeBytes(uint8_t reg, uint8_t *buf, uint8_t len)
{
    // 发送写入寄存器地址
    Wire.beginTransmission(MPU6887_ADDRESS);
    Wire.write(reg);
    // 写入数据
    for (int i = 0; i < len; i++)
    {
        Wire.write(buf[i]);
    }
    Wire.endTransmission();
}
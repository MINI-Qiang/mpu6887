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

//陀螺仪量程设置
void mpu6887::GYRO_SCOPE_CONFIG(uint8_t FS_SEL)
{
    
    //获取寄存器原始数据
    uint8_t temp;
    readBytes(GYRO_CONFIG, &temp, 1);
    //修改bit位置为[4:3]
    temp = (temp & 0b11100111) | (FS_SEL << 3);
    //写入寄存器
    writeBytes(GYRO_CONFIG, &temp, 1);

    _FS_SEL = FS_SEL;
}

//加速度量程设置
void mpu6887::ACCEL_SCOPE_CONFIG(uint8_t AFS_SEL)
{
    //获取寄存器原始数据
    uint8_t temp;
    readBytes(ACCEL_CONFIG, &temp, 1);
    //修改bit位置为[4:3]
    temp = (temp & 0b11100111) | (AFS_SEL << 3);
    //写入寄存器
    writeBytes(ACCEL_CONFIG, &temp, 1);
    _AFS_SEL = AFS_SEL;
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

//加速度的G值
float mpu6887::ACCEL_X_g()
{
    if(_AFS_SEL == Accel_2G)
    {
        float LBS = 16384;
        return (float)ACCEL_X() / LBS;
    }   
    else if(_AFS_SEL == Accel_4G)
    {
        float LBS = 8192;
        return (float)ACCEL_X() / LBS;
    }
    else if(_AFS_SEL == Accel_8G)
    {
        float LBS = 4096;
        return (float)ACCEL_X() / LBS;
    }
    else if(_AFS_SEL == Accel_16G)
    {
        float LBS = 2048;
        return (float)ACCEL_X() / LBS;
    }
    else
    {
        return 0;
    }
}

float mpu6887::ACCEL_Y_g()
{
    if(_AFS_SEL == Accel_2G)
    {
        float LBS = 16384;
        return (float)ACCEL_Y() / LBS;
    }   
    else if(_AFS_SEL == Accel_4G)
    {
        float LBS = 8192;
        return (float)ACCEL_Y() / LBS;
    }
    else if(_AFS_SEL == Accel_8G)
    {
        float LBS = 4096;
        return (float)ACCEL_Y() / LBS;
    }
    else if(_AFS_SEL == Accel_16G)
    {
        float LBS = 2048;
        return (float)ACCEL_Y() / LBS;
    }
    else
    {
        return 0;
    }
}

float mpu6887::ACCEL_Z_g()
{
    if(_AFS_SEL == Accel_2G)
    {
        float LBS = 16384;
        return (float)ACCEL_Z() / LBS;
    }   
    else if(_AFS_SEL == Accel_4G)
    {
        float LBS = 8192;
        return (float)ACCEL_Z() / LBS;
    }
    else if(_AFS_SEL == Accel_8G)
    {
        float LBS = 4096;
        return (float)ACCEL_Z() / LBS;
    }
    else if(_AFS_SEL == Accel_16G)
    {
        float LBS = 2048;
        return (float)ACCEL_Z() / LBS;
    }
    else
    {
        return 0;
    }
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

//陀螺仪的dps值
float mpu6887::GYRO_X_dps()
{
    if(_FS_SEL == Gyro_250dps)
    {
        float LBS = 131;
        return (float)GYRO_X() / LBS;
    }
    else if(_FS_SEL == Gyro_500dps)
    {
        float LBS = 65.5;
        return (float)GYRO_X() / LBS;
    }
    else if(_FS_SEL == Gyro_1000dps)
    {
        float LBS = 32.8;
        return (float)GYRO_X() / LBS;
    }
    else if(_FS_SEL == Gyro_2000dps)
    {
        float LBS = 16.4;
        return (float)GYRO_X() / LBS;
    }
    else
    {
        return 0;
    }
}

float mpu6887::GYRO_Y_dps()
{
    if(_FS_SEL == Gyro_250dps)
    {
        float LBS = 131;
        return (float)GYRO_Y() / LBS;
    }
    else if(_FS_SEL == Gyro_500dps)
    {
        float LBS = 65.5;
        return (float)GYRO_Y() / LBS;
    }
    else if(_FS_SEL == Gyro_1000dps)
    {
        float LBS = 32.8;
        return (float)GYRO_Y() / LBS;
    }
    else if(_FS_SEL == Gyro_2000dps)
    {
        float LBS = 16.4;
        return (float)GYRO_Y() / LBS;
    }
    else
    {
        return 0;
    }
}

float mpu6887::GYRO_Z_dps()
{
    if(_FS_SEL == Gyro_250dps)
    {
        float LBS = 131;
        return (float)GYRO_Z() / LBS;
    }
    else if(_FS_SEL == Gyro_500dps)
    {
        float LBS = 65.5;
        return (float)GYRO_Z() / LBS;
    }
    else if(_FS_SEL == Gyro_1000dps)
    {
        float LBS = 32.8;
        return (float)GYRO_Z() / LBS;
    }
    else if(_FS_SEL == Gyro_2000dps)
    {
        float LBS = 16.4;
        return (float)GYRO_Z() / LBS;
    }
    else
    {
        return 0;
    }
}

int16_t mpu6887::temperature_adc()
{
    uint8_t buf[2];
    readBytes(TEMP_OUT_H, buf, 2);
    return (((int16_t)buf[0]) << 8) | buf[1];
}

float mpu6887::temperature()
{
    return (float)temperature_adc() / 326.8 + 25;  // (TEMP_OUT[15:0]/Temp_Sensitivity) + RoomTemp_Offset 
    //where Temp_Sensitivity = 326.8 LSB/ºC and RoomTemp_Offset = 25ºC 
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
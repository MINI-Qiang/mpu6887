# ifndef __MPU6887_H__
# define __MPU6887_H__

# include <Arduino.h>
#include <Wire.h>

#define MPU6887_ADDRESS 0x68  //A0 LOW 0X68  A0 HIGH 0X69
#define MPU6887_DEVICE_ID         (0x2E)


# define Gyro_250dps  0x00
# define Gyro_500dps  0x01
# define Gyro_1000dps 0x02
# define Gyro_2000dps 0x03

# define Accel_2G  0x00
# define Accel_4G  0x01
# define Accel_8G  0x02
# define Accel_16G 0x03

/********* REGISTERS ADDRESS *************/
#define XG_OFFS_TC_H        0x04
#define XG_OFFS_TC_L        0x05
#define YG_OFFS_TC_H        0x07
#define YG_OFFS_TC_L        0x08
#define ZG_OFFS_TC_H        0x0A
#define ZG_OFFS_TC_L        0x0B

#define SELF_TEST_X_ACCEL   0x0D
#define SELF_TEST_Y_ACCEL   0x0E
#define SELF_TEST_Z_ACCEL   0x0F

#define XG_OFFS_USRH        0x13
#define XG_OFFS_USRL        0x14
#define YG_OFFS_USRH        0x15
#define YG_OFFS_USRL        0x16
#define ZG_OFFS_USRH        0x17
#define ZG_OFFS_USRL        0x18

#define SMPLRT_DI           0x19

#define CONFIG              0x1A
#define GYRO_CONFIG         0x1B
#define ACCEL_CONFIG        0x1C
#define ACCEL_CONFIG_2      0x1D   
#define LP_MODE_CFG         0x1E

#define ACCEL_WOM_X_THR     0x20
#define ACCEL_WOM_Y_THR     0x21
#define ACCEL_WOM_Z_THR     0x22
#define FIFO_EN             0x23

#define FSYNC_INT           0x36
#define INT_PIN_CFG         0x37
#define INT_ENABLE          0x38
#define FIFO_WM_INT_STATUS  0x39
#define INTSTATU            0x3A

#define ACCEL_XOUT_H        0x3B
#define ACCEL_XOUT_L        0x3C
#define ACCEL_YOUT_H        0x3D
#define ACCEL_YOUT_L        0x3E
#define ACCEL_ZOUT_H        0x3F
#define ACCEL_ZOUT_L        0x40
#define TEMP_OUT_H          0x41
#define TEMP_OUT_L          0x42
#define GYRO_XOUT_H         0x43
#define GYRO_XOUT_L         0x44
#define GYRO_YOUT_H         0x45
#define GYRO_YOUT_L         0x46
#define GYRO_ZOUT_H         0x47
#define GYRO_ZOUT_L         0x48

#define SELF_TEST_X_GYRO    0x50
#define SELF_TEST_Y_GYRO    0x51
#define SELF_TEST_Z_GYRO    0x52
#define E_ID0               0x53
#define E_ID1               0x54
#define E_ID2               0x55
#define E_ID3               0x56
#define E_ID4               0x57
#define E_ID5               0x58
#define E_ID6               0x59
#define FIFO_WM_TH1         0x60
#define FIFO_WM_TH2         0x61

#define SIGNAL_PATH_RESET   0x68
#define ACCEL_INTEL_CTRL    0x69
#define USER_CTRL           0x6A
#define PWR_MGMT_1          0x6B
#define PWR_MGMT_2          0x6C

#define I2C_IF              0x70
#define FIFO_COUNTH         0x72
#define FIFO_COUNTL         0x73
#define FIFO_R_W            0x74
#define WHO_AM_I            0x75

#define XA_OFFSET_H         0x77
#define XA_OFFSET_L         0x78
#define YA_OFFSET_H         0x7A
#define YA_OFFSET_L         0x7B
#define ZA_OFFSET_H         0x7D
#define ZA_OFFSET_L         0x7E

#define GYRO_AXIS_DIR     {1, 2, 3}

#define MAX_I2C_RESTORE_SCL_CNT       (8 * 32)
///#define PI 3.1415926535
#define ACC_FILTER                    (0.8)
#define TILT_ANGLE_FILTER             (0.4)
#define TILT_RANGE_GAIN               (0.2588) // cos(75)
#define ARROW_ORIENTATION_RANGE_GAIN  (0.2588) // cos(75)   
#define SCREEN_STATUS_RANGE_GAIN      (0.906) //  cos(25)   
#define SHAKE_CHECK_DATA_BUFFER_SIZE  (60)
#define GRAVITY_DEFAULT_VALUE         (17000 / 2)
#define I2C_NUM                       (I2C_NUM_1)
#define I2C_FREQUENCY                 (400000)

#define SHAKE_STRENGTH_FREQUENCY_GAIN (4)       // this is a empirical value (0 - 20)
#define SHAKE_STRENGTH_ACC_VALUE_GAIN (5.0 / GRAVITY_DEFAULT_VALUE)   // this is a empirical value
#define SHAKE_STRENGTH_START_CHECK_GAIN (0.05)

#define SHAKED_THRESHOLD_DEFAULT      (20)
#define SHAKED_THRESHOLD_MAX          (80)
#define SHAKED_THRESHOLD_MIN          (10)

#define BRANDISH_CHECK_START_THRESHOLD      (100)
#define BRANDISH_CHECK_THRESHOLD            (300)

#define GTRO_SENSITIVITY_DEFAULT      (65.5) // for 500 deg/s, check data sheet
#define GYRO_UPDATE_THRESHOLD_ACC     (100)  // acc
#define GYRO_UPDATE_THRESHOLD_GYRO    (10)   // gyro  

class mpu6887
{
private:
    /* data */
    
    uint8_t _AFS_SEL;  //当前加速度量程设置
    uint8_t _FS_SEL;  //当前陀螺仪量程设置
public:
    mpu6887();
    //~mpu6887();
    void begin();
    void init();
    uint8_t getDeviceID(); //获取设备ID

    void GYRO_SCOPE_CONFIG(uint8_t FS_SEL = Gyro_250dps);//陀螺仪量程设置
    void ACCEL_SCOPE_CONFIG(uint8_t AFS_SEL = Accel_2G);//加速度量程设置

    //采样率设置


    int16_t  ACCEL_X();  //加速度X轴实时数据原始ADC值
    float  ACCEL_X_g();  //加速度X轴实时数据g值
    int16_t  ACCEL_Y();  //加速度Y轴实时数据原始ADC值
    float  ACCEL_Y_g();  //加速度Y轴实时数据g值
    int16_t  ACCEL_Z();  //加速度Z轴实时数据原始ADC值
    float  ACCEL_Z_g();  //加速度Z轴实时数据g值
    int16_t  GYRO_X();   //陀螺仪X轴实时数据原始ADC值
    float  GYRO_X_dps();   //陀螺仪X轴实时数据dps值
    int16_t  GYRO_Y();   //陀螺仪Y轴实时数据原始ADC值
    float  GYRO_Y_dps();   //陀螺仪Y轴实时数据dps值
    int16_t  GYRO_Z();   //陀螺仪Z轴实时数据原始ADC值
    float  GYRO_Z_dps();   //陀螺仪Z轴实时数据dps值
    int16_t  TEMP();     //温度实时数据


    //通用读写函数
    void readBytes(uint8_t reg, uint8_t *buf, uint8_t len);  //读取数据
    void writeBytes(uint8_t reg, uint8_t *buf, uint8_t len); //写入数据

};

# endif
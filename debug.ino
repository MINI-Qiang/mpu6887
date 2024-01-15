#include <Wire.h>

// Replace this with your I2C device's actual address
const int deviceAddress = 0x68;  //A0 low 0X68  A0 HIGH 0X69
// Register to read from
const int registerAddress = 0x05;

void setup()
{
  Wire.setSDA(12); // Set the SDA pin, if necessary for your board
  Wire.setSCL(13); // Set the SCL pin, if necessary for your board
  Wire.begin();    // Start the I2C Bus
  Serial.begin(115200); // Start serial communication at 9600 baud rate
}

void loop()
{
  Wire.beginTransmission(deviceAddress); // Initialize communication with the device
  Wire.write(registerAddress);           // Send the register address where you want to read from
  Wire.endTransmission();           // End transmission but keep the connection active (useful for repeated start condition)
  
  Wire.requestFrom(deviceAddress, 1);    // Request 1 byte of data from the current position (register 0x01)
  byte data = Wire.read();             // Read the byte of data from the I2C bus
  Serial.print("Data read from register 0x04: ");
  Serial.println(data, HEX);           // Print the data in hexadecimal format

  delay(1000);                           // Wait for a second before the next read operation
}
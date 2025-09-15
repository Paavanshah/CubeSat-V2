#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Scale factors for the MPU6050 (for a +/- 2g accel and +/- 250 deg/s gyro range)
const float ACCEL_SCALE_FACTOR = 16384.0;
const float GYRO_SCALE_FACTOR = 131.0;
const float GRAVITY = 9.80665; // Earth's gravity in m/s^2

void setup() {
  Serial.begin(9600);
  Serial.println("MPU6050 Acceleration and Gyro Test");
  
  Wire.begin();
  mpu.initialize();
  
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1) {}
  }
  Serial.println("MPU6050 connection successful!");
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  // Read raw motion data
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Convert raw accelerometer values to m/s^2
  float accelX = ((float)ax / ACCEL_SCALE_FACTOR) * GRAVITY;
  float accelY = ((float)ay / ACCEL_SCALE_FACTOR) * GRAVITY;
  float accelZ = ((float)az / ACCEL_SCALE_FACTOR) * GRAVITY;

  // Convert raw gyroscope values to degrees per second
  float gyroX = (float)gx / GYRO_SCALE_FACTOR;
  float gyroY = (float)gy / GYRO_SCALE_FACTOR;
  float gyroZ = (float)gz / GYRO_SCALE_FACTOR;

  // Print precise acceleration data in m/s^2 format
  Serial.print("Accel (m/s^2): ");
  Serial.print("X=");
  Serial.print(accelX);
  Serial.print(", Y=");
  Serial.print(accelY);
  Serial.print(", Z=");
  Serial.println(accelZ);

  // Print precise gyroscope data in deg/s format
  Serial.print("Gyro (deg/s):  ");
  Serial.print("X=");
  Serial.print(gyroX);
  Serial.print(", Y=");
  Serial.print(gyroY);
  Serial.print(", Z=");
  Serial.println(gyroZ);
  
  Serial.println("------------------------------------");
  delay(1000);
}
#include <Servo.h>
#include <MPU6050.h>

MPU6050 IMU(4,5);
Servo servo;

void setup() {
  // put your setup code here, to run once:
  IMU.initialize();
  IMU.calibrate();
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  float accelX = IMU.get_accel('x');
  float servoPos = 90 + (accelX * 90);
  IMU.update();
  servo.write(servoPos);
}

#include <MPU6050.h>

#define SDA 4
#define SCL 5

MPU6050 sensor(SDA, SCL);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Begin distance sensor
  sensor.initialize();
  sensor.update();
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor.update();
  Serial.print ("accel x: ");
  Serial.println(sensor.get_accel('x'));
  delay(1000);
  Serial.print("accel y: ");
  Serial.println(sensor.get_accel('y'));
  delay(1000);
  //Serial.println(sensor.get_ang_vel('y'));
  Serial.print("accel z: ");
  Serial.println(sensor.get_accel('z'));
  //Serial.println(sensor.get_ang_vel('z'));
  delay(1000);

}

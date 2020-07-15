#include <motor_control.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  //forward(200)
  //raw_motor_control(200,176);
  //raw_motor_control(100, 80);
  double scale = 0.84;
  double value = 220;
  raw_motor_control(value, value * scale);
  //raw_motor_control(70,70);
}

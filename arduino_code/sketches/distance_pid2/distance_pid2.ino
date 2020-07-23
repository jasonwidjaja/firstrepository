#include <motor_control.h>
#include <MPU6050.h>
#include <State.h>

//Global Variables
#define SDA 4
#define SDA 5
#define MPU6050_ADDRESS 0*68;

MPU6050 sensor(SDA,SCL);

#include <PID_v1.h>
double base_motor_speed = 140;
double setpoint = 0;
double input;
double output;
double kp = 3.5;
double ki = 0.5;
double kd = 0.04;


PID controller(&input, &output, &setpoint, kp, ki, kd, AUTOMATIC);
State controller_state;

void setup() {
 Serial.begin(9600);
 sensor.initialize();
 sensor.update();

 controller.SetOutputLimits(-200,200);
 controller.SetSampleTime(50);
 controller.SetMode(1);

 controller_state.setLinearState(150);
 controller_state.setRotationState(90);
}

void loop() {
  sensor.update();
  input = sensor.get_ang_vel('z');

  controller.Compute();
  //controller_state.setLinearState(controller_state.getLinearState() * -1);
  //raw_motor_control(base_motor_speed + output + 50 , base_motor_speed - output);
  raw_motor_control(controller_state.getLinearState() + output, controller_state.getLinearState() - output);
  //Serial.println(controller_state.getLinearState());
  //Serial.print("output: "); 
  //Serial.println(output);
  
}

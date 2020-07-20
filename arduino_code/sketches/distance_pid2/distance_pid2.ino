#include <HC_SR04.h>
#include <PID_v1.h>
#include <motor_control.h>
#include <Servo.h>
#include <MPU6050.h>

//Global Variables
#define TRIG_PIN 10
#define ECHO_PIN 2
#define ECHO_INT 0

HC_SR04 sensor(TRIG_PIN, ECHO_PIN, ECHO_INT);
Servo actuator;
MPU6050 IMU(4,5);

double base_motor_speed = 150;
double setpoint = 5;
float input;
double output;
double kp = 20;
double ki = 0;
double kd = 0;
double switch_time = millis();
double accelX = input/(switch_time * switch_time);
PID controller(&input, &output, &setpoint, kp, ki, kd, REVERSE);


void setup() {
  //setup motors
  motor_setup();

  IMU.initialize();
  IMU.calibrate();
  
  //setup servo and point forward
  actuator.attach(9);
  actuator.write(90);

  //initialize distance sensor
  sensor.begin();
  sensor.start();

  //Set PID parameters
  controller.SetOutputLimits(-130, 130);
  controller.SetSampleTime(30);
  controller.SetMode(1);

  //begin serial for debugging
  Serial.begin(9600);
}

void loop() {
  // get distance value from sensor, update input to be distance value
  if(sensor.isFinished())
  {
    input = sensor.get_ang_vel('z');
    sensor.start(); // restart sensor
  }
  if(millis() > switch_time + 1000)
  {
    setpoint *= -1;
  }
  
  
  //compute PID controller once input has been updated
  controller.Compute();
  
  //set motor power based on output from PID controller
  raw_motor_control(base_motor_speed + output,base_motor_speed - output);//use scale factor if drifts left, increase left
  
  Serial.print("output: "); 
  Serial.print(output);
  Serial.print(" distance: ");
  Serial.println(input);
}

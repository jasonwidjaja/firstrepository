#include <HC_SR04.h>
#include <PID_v1.h>
#include <motor_control.h>
#include <Servo.h>

//Global Variables
#define TRIG_PIN 10
#define ECHO_PIN 2
#define ECHO_INT 0

HC_SR04 sensor(TRIG_PIN, ECHO_PIN, ECHO_INT);
Servo actuator;

double setpoint = 5;
double input;
double output;
double kp = 50;
double ki = 0;
double kd = 3;
double switch_time = millis();
double accelX = input/(switch_time * switch_time);
PID controller(&input, &output, &setpoint, kp, ki, kd, REVERSE);


void setup() {
  //setup motors
  motor_setup();
  
  
  //setup servo and point forward
  actuator.attach(9);
  actuator.write(90);

  //initialize distance sensor
  sensor.begin();
  sensor.start();

  //Set PID parameters
  controller.SetOutputLimits(-250, 250);
  controller.SetSampleTime(30);
  controller.SetMode(1);

  //begin serial for debugging
  Serial.begin(9600);
}

void loop() {
  // get distance value from sensor, update input to be distance value
  if(sensor.isFinished())
  {
    input = sensor.getRange();
    sensor.start(); // restart sensor
  }
  if(millis() > switch_time + 1000)
  {
    setpoint *= -1;
  }
  
  
  //compute PID controller once input has been updated
  controller.Compute();
  
  //set motor power based on output from PID controller
  raw_motor_control(output,output );//use scale factor if drifts left, increase left
  
  Serial.print("output: "); 
  Serial.print(output);
  Serial.print(" distance: ");
  Serial.println(input);
}

/*include all libraries: SODAR, PID, HCSR04, Servo, State, Motor Control, MPU6050
 *define all global variables for all libraries
 *servo variable
 *SODAR initialization
 *define pins for HCSR04 
 *sensor object for HCSR04
 *accel  object for MPU6050
 *controller_state object for State Class
 */

void setup() {
  /* put your setup code here, to run once:
   *set up motor
   *set up servo to point forward
   *initialize distance sensor(HCSR04)
   *initialize MPU6050 (initialize and calibrate method)
   *Set PID Parameters
   *set Linear and Rotation State for State Class
   */
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //update all necessary objects for libraries such as SODAR,etc
  /*if distance is not within 20 cm, make servo turn in respective direction using a 
   *for loop and increment 45 form 0
   *set a variable and compare it to find greatest distance that 
   *the sensor detected
   *if object is surrounded with obstacles within the conditions, allow car to turn around (180 deg turn) and continue in that direction
   */
   //
    // compute PID controller
    //set motor power based on output from PID controller
   
}

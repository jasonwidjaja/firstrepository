4}// Circle Class
class Circle {
   // Private variables that can only be accessed within the class
   double radius;
   // Place private variables here.
   
  // Everything after "public" can be accesed outside of the class (i.e in "setup" or "loop")
  public:
    // Put a constructor here: What information is needed?
    Circle(double);
    // Create a function that returns area (use 3.14 for pi)
    double area()
    {
      return 3.14 * radius * radius;
    }
    
    // Create a function that allows the user to update the values
    void setRadius(double rad)
    {
      radius = rad;
    }
  
};

// Definitions of functions declared above
    Circle::Circle(double r)
    {
      radius = r;
    }

void setup() {
  // Instantiates the Circle class
    Circle c(5.0);
  // Can only print after serial.begin()
  Serial.begin(9600);
  // Calls the area() function within the class
    double area = c.area();
  // Prints area
    Serial.println(area);
  // Updates values
    c.setRadius(4.0);
    area = c.area();
  // Prints new areas
  Serial.println(area);
}


void loop() {
  // put your main code here, to run repeatedly:
}

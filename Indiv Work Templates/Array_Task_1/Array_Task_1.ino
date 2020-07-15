// Array Task 1

void setup() {
  Serial.begin(9600);

  // Create an array of type int and size 10:
   int arr[10];
  // Using a while loop, fill the array with multiples of 3 between 3 and 30 (inclusive):
                // Remember the syntax?
                // while (condition) {
                //       code...
                // }
                int i = 0;
                while(i <= 9)
                {
                  arr[i] = 3 * (i + 1);
                  Serial.println(arr[i]);
                  i++;
                }
                



  // Rewrite the code above with a for loop:
                // Remember the syntax?
                // for (initialization; condition; update variable) {
                //       code...
                // }
                for(int j = 1; j <= 10; j++)
                {
                 arr[j] = 3 * j;
                  
                }


  // Write a loop that will go through the array 
  //     and print any values that are a multiple of 9:
                // Hint: Use the % (modulus) operator.
      for(int k = 0; k < 10; k++)
      {
        if(arr[k] % 9 == 0)
        {
          Serial.println(arr[k]);
        }
      }

}

void loop() {
  // put your main code here, to run repeatedly:

}

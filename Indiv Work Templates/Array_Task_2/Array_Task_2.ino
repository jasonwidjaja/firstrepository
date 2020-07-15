// Array Task 2

int len = 100;

void setup() {
  Serial.begin(9600);

  // Creates an array of size len
  int arr[len];
  
  // Fills the array with random values
  for(int i = 0; i < len; i++){
    int r = random(1000);
    arr[i] = r;
  }
  Serial.println(findMax(arr,len));
  Serial.println(findMin(arr,len));

}

void loop() {}

// Fill in function that will return the largest value in the array
int findMax(int arr[], int len){
  int maxArr = arr[1];
  for(int i = 1; i < len; i++)
  {
    if(maxArr < arr[i - 1])
    {
      maxArr = arr[i - 1];
    }
  }
  return maxArr;
}

// Fill in function that will return the smallest value in the array
int findMin(int arr[], int len){
  int minArr = arr[1];
  for(int j = 1; j < len; j++)
  {
    if(minArr > arr[j - 1])
    {
      minArr = arr[j - 1];
    }
  }
  return minArr;
}

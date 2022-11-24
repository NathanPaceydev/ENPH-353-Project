//set global variables
const int Sensor = A0;        //the analog pin the Joystick X Axis  is connected to
int sensorReading = 0;             //variable to store the value read from the sensor
int readingDelay = 10;
const float factor = 0.245;
const float zeroIntercept = 198.5;
String start;


//set up the elements of this sketch
void setup() 
{
  Serial.begin(115200);
  Serial.println("Enter 1 to start");
}

void loop() 
{
  while (Serial.available() == 0){}
  int menuChoice = Serial.parseInt();
  
  if (menuChoice == 1){
    while(0!=1){
      Read_and_write();
    }
  }
  
}

void Read_and_write()
{
  //delay(readingDelay);
  //store the readings from the Joystick as "sensorReading"
  sensorReading = analogRead(Sensor);   
  
  //Serial.println(sensorReading);
  //Serial.print(" ");
  float B = factor*(sensorReading-zeroIntercept);
  Serial.print(B);
  Serial.println();
}


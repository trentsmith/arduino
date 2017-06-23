const int trigPin = 9;
const int echoPin = 10;
int x;
int average =0;
int result =0;
// defines variables
const int S1 =7;
const int p1 =6;
long duration;
int distance;
void setup() 
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(S1,OUTPUT);
  pinMode(p1,INPUT);
  Serial.begin(9600); // Starts the serial communication
}
void loop() 
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("Distance: ");
  x = analogRead(p1);
  result = distance-average;
  Serial.println(result);
    Serial.println(x);
  if(average > distance)
  {
    average--;
  }
  else if( average <distance)
  {
    average=average+2;
  }
    if(distance<100)
    {
      analogWrite(S1,0);
    }
     else if(distance>500)
    {
      analogWrite(S1,255);
    }
}

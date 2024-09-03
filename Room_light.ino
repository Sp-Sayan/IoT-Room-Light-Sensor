
const int trigPin = 7;
const int echoPin = 8;
const int relay = 9;
int sense[2] = {0,255};

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  long duration, inches, cm;

  digitalWrite(trigPin, LOW);         //Initialize trigger with low pulse
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);              //HC-SR04 needs 10 microsecond to take measurement
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);  //amount of time ECHO is HIGH is the measurement

  
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  if(inches <= 65 && inches >=35)
  {
    analogWrite(relay, sense[1]);
    Swap(sense);
    delay(1000);
  }

  Serial.print("Distance: ");
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(1000);
}
long microsecondsToInches(long microseconds) {
  return microseconds/148;
}

long microsecondsToCentimeters(long microseconds) {

  return microseconds / 58;
}
int Swap(int sense[])
{
  int temp = sense[0];
  sense[0] = sense[1];
  sense[1] = temp;
}
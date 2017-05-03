const int trigPin = 13;
const int echoPin = 12;
const int LF = 8; //LF
const int LB = 7; //LB
const int RF = 5; //RF
const int RB = 6; //RB


void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (LF, OUTPUT);
  pinMode (LB, OUTPUT);
  pinMode (RF, OUTPUT);
  pinMode (RB, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LF, HIGH);
  digitalWrite(RF, HIGH);
}
long duration, distance;

void loop()
{     
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.println(distance);
  if(distance<20)
    {
      digitalWrite(LF, LOW); 
      digitalWrite(LB, HIGH); 
      digitalWrite(RF, HIGH); 
      digitalWrite(RB, LOW);
    }
  else{
      digitalWrite(LF, HIGH); 
      digitalWrite(LB, LOW);
      digitalWrite(RF, HIGH); 
      digitalWrite(RB, LOW);
  }
}

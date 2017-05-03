/*
 * Ultrasonic sensor, make buggy slow when it approaches an obstacle. Eventually stop it.
 * author: Sarthak, Santosh , Saransh
 */

int trig = 13;
int echo = 12;
int motorRF = 5;
int motorLB = 6;
int motorLF = 8;
int motorRB = 7;

int multiplier = 10;
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motorLF, OUTPUT);
  pinMode(motorLB, OUTPUT);
  pinMode(motorRF, OUTPUT);
  pinMode(motorRB, OUTPUT);
  setAllLow();
  //startMoving();
  Serial.begin(9600);
}

void loop() {
  Serial.println(distanceOfObject());
  if(distanceOfObject() > 5){
    startMoving();
  }
  else{
    digitalWrite(motorLF, LOW);
    digitalWrite(motorRF, LOW);
    /*
     * uncomment the below lines and comment the above two if you want to make to slow
     * proportional to approaching distance
     */
//    analogWrite(motorLF, (distanceOfObject()-1)*multiplier);
//    analogWrite(motorRF, (distanceOfObject()-1)*multiplier);
  }
}
void startMoving(){
  digitalWrite(motorLF, HIGH);
  digitalWrite(motorRF, HIGH);
}

void setAllLow(){
  digitalWrite(motorLF, LOW);
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRF, LOW);
  digitalWrite(motorRB, LOW);
}

long distanceOfObject(){
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration/2/29.1;
  return distance;
}


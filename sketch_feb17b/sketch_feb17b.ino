/*
 * Line follower: Both Black
 * author: Sarthak, Santosh , Saransh
 */

 /*
  * Right Sensor: A0
  * Left Sensor: A1
  */
int lSensor = A0;
int rSensor = A1;
int motorRF = 5;
int motorLB = 6;
int motorLF = 8;
int motorRB = 7;
void setup() {
  pinMode(lSensor, INPUT);
  pinMode(rSensor, INPUT);
  pinMode(motorLF, OUTPUT);
  pinMode(motorLB, OUTPUT);
  pinMode(motorRF, OUTPUT);
  pinMode(motorRB, OUTPUT);
  setAllLow();
  startMoving();
  Serial.begin(9600);
}

void loop() {
  int lSensorValue = analogRead(lSensor);
  lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
  int rSensorValue = analogRead(rSensor);
  rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
  if(lSensorValue >0 && rSensorValue == 0){
    digitalWrite(motorRF, LOW);
    digitalWrite(motorLF, HIGH);

  }
  else if(lSensorValue == 0 && rSensorValue > 0){
    digitalWrite(motorLF, LOW);
    digitalWrite(motorRF, HIGH);
  }
  else if(lSensorValue == 0 && rSensorValue == 0){
    startMoving();
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


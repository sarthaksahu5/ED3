int lSensor = A2;
int rSensor = A3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(lSensor, INPUT);
  pinMode(rSensor, INPUT);
}

void loop() {
  
  int lSensorValue = analogRead(lSensor);
  lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
  int rSensorValue = analogRead(rSensor);
  rSensorValue = map(rSensorValue, 0, 1023, 0, 255);

  Serial.print(lSensorValue);
  Serial.print("  ");
  Serial.print(rSensorValue);
  Serial.println("");
  delay(200);
}

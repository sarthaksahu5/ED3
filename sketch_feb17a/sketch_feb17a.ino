/*
 * Read value from IR sensor
 * author: Sarthak, Santosh , Saransh
 */
int sensor = A1;
void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(sensor);
  val = map(val, 0, 1023, 0, 255);
  Serial.println(val);
  delay(1000);
}

int sensorPin = A0;
int ledPin = 3;

int sensorValue = 0;
int sensorValueMapped = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  //digitalWrite(ledPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  sensorValueMapped = map(sensorValue, 0, 1023, 0, 255);
  Serial.print(" sensor value: ");
  Serial.print(sensorValue);
  Serial.print("\nMapped : ");
  Serial.print(sensorValueMapped);
  analogWrite(ledPin, sensorValueMapped);
  
}

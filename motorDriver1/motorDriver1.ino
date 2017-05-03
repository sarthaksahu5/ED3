int motor = 10;
int enabled  = 11
int pot = A0;
int val = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(motor,OUTPUT);
  pinMode(enabled, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
  val = analogRead(pot);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(enabled,val);
  digitalWrite(motor, HIGH);
}

void setup() {
  // put your setup code here, to run once:
for(int i=5;i<=8;i++)
pinMode(i,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


digitalWrite(5,HIGH);
digitalWrite(8,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
delay(300);
digitalWrite(5,HIGH);
digitalWrite(8,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
delay(300);



}

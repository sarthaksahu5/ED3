void setup() {
  // put your setup code here, to run once:
for(int i=5;i<=8;i++)
pinMode(i,OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:

for(int i=98;i>=0;--i)
{digitalWrite(8,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
delay(30);
digitalWrite(5,HIGH);
digitalWrite(8,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
delay(75);}
for(int i=98;i>=0;--i)
{digitalWrite(8,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
delay(30);
digitalWrite(8,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
delay(65);}

}

/*
 * Program to draw 8 using buggy
 * @author: Sarthak, Santosh, Saransh
*/
int leftF = 5;
int leftB = 6;
int rightF = 8;
int rightB = 7;


void setup() {
  pinMode(leftF,OUTPUT);
  pinMode(leftB,OUTPUT);
  pinMode(rightF,OUTPUT);
  pinMode(rightB,OUTPUT);
}

void loop() {
  for(int i=0; i<750; i++)
    circle1();
  for(int i=0; i<750; i++)
    circle2();
}

void circle1()
{
  digitalWrite(leftF, HIGH);
  digitalWrite(rightF, HIGH);
  digitalWrite(leftB, LOW);
  digitalWrite(rightB, LOW);
  delay(10);
  digitalWrite(leftF, HIGH);
  digitalWrite(rightF, LOW);
  digitalWrite(leftB, LOW);
  digitalWrite(rightB, LOW);
  delay(10);  
}

void circle2()
{
  digitalWrite(leftF, HIGH);
  digitalWrite(rightF, HIGH);
  digitalWrite(leftB, LOW);
  digitalWrite(rightB, LOW);
  delay(10);
  digitalWrite(rightF, HIGH);
  digitalWrite(leftF, LOW);
  digitalWrite(leftB, LOW);
  digitalWrite(rightB, LOW);
  delay(10);  
  
  
}

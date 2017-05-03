/*
 * Program to draw Circle using buggy
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
  //Draw Circle1
  for(int i=0; i<325; i++){
    circle1();
  }
  digitalWrite(leftF,LOW);
  digitalWrite(leftB,LOW);
  digitalWrite(rightF,LOW);
  digitalWrite(rightB,LOW);
  //Draw Circle2
  for(int i=0; i<375; i++){
    circle2();
  }
  digitalWrite(leftF,LOW);
  digitalWrite(leftB,LOW);
  digitalWrite(rightF,LOW);
  digitalWrite(rightB,LOW);
}

void loop() {
}

void circle1()
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
void circle2()
{
  digitalWrite(leftB, HIGH);
  digitalWrite(rightB, HIGH);
  digitalWrite(leftF, LOW);
  digitalWrite(rightF, LOW);
  delay(10);
  digitalWrite(leftB, HIGH);
  digitalWrite(rightB, LOW);
  digitalWrite(leftF, LOW);
  digitalWrite(rightF, LOW);
  delay(10);   
}

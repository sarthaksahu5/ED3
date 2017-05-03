/*
 * Program to draw 3 using buggy
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
  digitalWrite(leftB, LOW);
  digitalWrite(rightB, LOW);
  //Draw circle
   for(int i=0; i<375; i++)
    circle();

   digitalWrite(leftF, LOW);
   digitalWrite(rightF, LOW);
   //turn 180 degree
   digitalWrite(rightF, HIGH);
   digitalWrite(leftF,LOW);
   delay(3000);
   digitalWrite(leftF, LOW);
   digitalWrite(rightF, LOW);
   //draw circle
   for(int i=0; i<375; i++)
    circle();
}

void loop() {
}

void circle()
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


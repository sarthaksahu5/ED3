/*
 * Program to draw 4 using buggy
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
  setLow();
  //go straight
  digitalWrite(leftF, HIGH);
  digitalWrite(rightF, HIGH);
  delay(3000);
  //turn
  digitalWrite(rightF,LOW);
  digitalWrite(leftF,HIGH);
  delay(1500);
  //go straight
  digitalWrite(leftF, HIGH);
  digitalWrite(rightF, HIGH);
  delay(3000);
  //turn
  digitalWrite(rightF,LOW);
  digitalWrite(leftF,HIGH);
  delay(1500);
  //go straight
  digitalWrite(leftF, HIGH);
  digitalWrite(rightF, HIGH);
  delay(3000);
  setLow();
  // Go Reverse
  digitalWrite(leftB,HIGH);
  digitalWrite(rightB,HIGH);
  delay(6000);
  setLow();
}

void loop() {
}

void setLow(){
  digitalWrite(leftF,LOW);
  digitalWrite(leftB,LOW);
  digitalWrite(rightF,LOW);
  digitalWrite(rightB,LOW); 
}


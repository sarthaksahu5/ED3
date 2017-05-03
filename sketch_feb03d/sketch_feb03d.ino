//5
int leftF = 5;
int leftB = 6;
int rightF = 8;
int rightB = 7;


void setup() {
  // put your setup code here, to run once:
  pinMode(leftF,OUTPUT);
  pinMode(leftB,OUTPUT);
  pinMode(rightF,OUTPUT);
  pinMode(rightB,OUTPUT);
  digitalWrite(leftB, LOW);
  digitalWrite(rightB, LOW);
  
  lineFive();
  /*
  digitalWrite(rightF, LOW);
  digitalWrite(leftF, HIGH);
  delay(1450);
  digitalWrite(leftF, LOW);
  digitalWrite(rightF, LOW);
  */
  for(int i=0; i<300; i++)
    circle();
  digitalWrite(leftF, LOW);
  digitalWrite(rightF, LOW);
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

void lineFive()
{

  //Go straight
  digitalWrite(leftF, HIGH);
  digitalWrite(rightF, HIGH);
  delay(2500);
  //Turn
  digitalWrite(leftF, HIGH);
  digitalWrite(rightF, LOW);
  delay(1450);  
  //Go straight
  digitalWrite(leftF, HIGH);
  digitalWrite(rightF, HIGH);
  delay(2500);
  //Turn
  digitalWrite(rightF, LOW);
  digitalWrite(leftF, HIGH);
  delay(1450);
  //Go straight
  digitalWrite(leftF, HIGH);
  digitalWrite(rightF, HIGH);
  delay(1800); 
  //All Low
  digitalWrite(rightF, LOW);
  digitalWrite(leftF, LOW);
}

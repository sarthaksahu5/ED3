#include <NewPing.h>

int TRIGGER = 13;
int ECHO = 12;
int startTime = 0;
long endTime = 0;
int counter = 0;
bool logic1 = false;
bool logic2 = false;


NewPing sonar(TRIGGER, ECHO);


void setup() {
  Serial.begin(115200);
}
int distance = 0;
void loop() {
  
  if(endTime >= 100000 && counter < 9)
  {
    if(sonar.ping_cm() < 15 && logic1 == false)
    {
      distance = sonar.ping_cm();
      logic1 = true;
      delay(50);
    }
    if(sonar.ping_cm() > 100 && logic1)
    {
      logic2 = true;  
    }
    if(logic1 && logic2)
    {
      Serial.println(distance);
      counter++;  
      logic1 = false;
      logic2 = false;
    }
    endTime = 0;
  }
  if(counter == 9)
  {
    Serial.println("BAS BHAI !");
    while(true){
      
    }
  }
//  if(endTime >= 100000){
//    Serial.println(sonar.ping_cm());
//    endTime = 0;
//  }
  endTime++;
}

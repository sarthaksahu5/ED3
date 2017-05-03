/*
 * ED3 Final Project
 * @author: Sarthak Sahu, Santosh Gupta, Sanat Kumar Jain
 */


#include <NewPing.h>

int TRIGGER = 13;
int ECHO = 12;
long store;
NewPing sonar(TRIGGER, ECHO);

int motorRF = 5;
int motorLF = 8;
int motorLB = 7;
int motorRB = 6;
int lSensor = A2;
int rSensor = A1;
bool black = 0;
bool white = !black;
int distance = 0;

/*
 * logic1 becomes true when the we encounter two black lines.
 * Two black lines means that we are on an intersection or the finish line.
 * We increase the intersectionCounter only when we come out of the two black lines. 
 * This way our intersectionCounter works accurately.
 */


bool logic1 = false;
bool logic2 = false;
int intersectionCounter = 0;
int obstacleCounter = 0;

void setup() {
  Serial.begin(115200);
  pinMode(motorRF, OUTPUT);
  pinMode(motorLF, OUTPUT);
  pinMode(motorLB, OUTPUT);
  pinMode(motorRB, OUTPUT);
  //start();
  start1();
}

void forward(){
  digitalWrite(motorRF, HIGH);
  digitalWrite(motorLF, HIGH);
}

void turnRight(){
  digitalWrite(motorRF, LOW);
  digitalWrite(motorLF, HIGH);
}

void turnLeft(){
  digitalWrite(motorRF, HIGH);
  digitalWrite(motorLF, LOW);
}

void stopMoving(){
  digitalWrite(motorLF, LOW);
  digitalWrite(motorRF, LOW);
}

void park(){
    while(true){
    int lSensorValue = analogRead(lSensor);
    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
    int rSensorValue = analogRead(rSensor);
    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
    
    if(rSensorValue < 100 && lSensorValue < 100){
      stopMoving();
      while(true){
      }
    }else if(rSensorValue < 100 && lSensorValue > 100){
      turnRight();
    }else if(rSensorValue > 100 && lSensorValue < 100){
      turnLeft();
    }else if(rSensorValue > 100 && lSensorValue > 100){
      forward();
    }
  }
}
/*
* Change this function accordingly for gold task.
*/
void rotateTillBothBecomeWhite(){
  logic1 = false;
  logic2 = false;
  while(true){
    int lSensorValue = analogRead(lSensor);
    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
    int rSensorValue = analogRead(rSensor);
    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
    
    if(lSensorValue > 100 && rSensorValue > 100){
      break;
    }
    digitalWrite(motorRF, HIGH);
    digitalWrite(motorLB, HIGH);
  }
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRB, LOW);
  //rotate till sensors allign perfectly.
  while(true){
    int lSensorValue = analogRead(lSensor);
    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
    int rSensorValue = analogRead(rSensor);
    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
    
    digitalWrite(motorRF, HIGH);
    digitalWrite(motorLB, HIGH);

    if(lSensorValue < 100 && rSensorValue > 100 && !logic1){
      logic1 = true;
    }
    if(lSensorValue > 100 && rSensorValue > 100 && logic1){
      logic2 = true;
    }
    if(logic1 == true && logic2 == true){
      break;  
    }
  }
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRB, LOW);
  park();
}
/*
 * This is the actual function we will use for the silver as well as gold task.
 */
void start1(){
  long endTime = 0;
  while(true){
    
    int lSensorValue = analogRead(lSensor);
    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
    int rSensorValue = analogRead(rSensor);
    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
    
    if(endTime >= 1000){
      distance = sonar.ping_cm();
      if(distance < 20 && logic1 == false){
        Serial.print("YES!");
        stopMoving();
        delay(1000);
        logic1 = true;
        store = distance;
      }
 
      if(sonar.ping_cm() > 100 && logic1 == true){
        Serial.print("  Oh Yeah!");
        logic2 = true;
      }
      if(logic1 == true && logic2 == true){
        logic1 = false;
        logic2 = false;
        Serial.println(store);
        obstacleCounter++;  
      }
      endTime = 0;
    }
    if(rSensorValue < 100 && lSensorValue < 100){
      forward();
    }else if(rSensorValue < 100 && lSensorValue > 100){
      turnRight();
    }else if(rSensorValue > 100 && lSensorValue < 100){
      turnLeft();
    }else if(rSensorValue > 100 && lSensorValue > 100){
      forward();
    }
    if(obstacleCounter == 9){
      break;
    }
    endTime++;
    //Serial.println(sonar.ping_cm());
  }
  while(true){
    int lSensorValue = analogRead(lSensor);
    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
    int rSensorValue = analogRead(rSensor);
    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
    
    if(rSensorValue <100 && lSensorValue < 100){
      forward();
      logic1 = true;
    }else if(rSensorValue < 100 && lSensorValue > 100){
      turnRight();
      if(logic1 == true)
        logic2 = true;
    }else if(rSensorValue > 100 && lSensorValue < 100){
      turnLeft();
      if(logic1 == true)
        logic2 = true;
    }else if(rSensorValue > 100 && lSensorValue > 100){
      forward();
    }
    if(logic1 == true && logic2 == true){
      logic1 = false;
      logic2 = false;
      intersectionCounter++;
    }
    if(intersectionCounter == 1){
      break;
    }
  }
  stopMoving();
  rotateTillBothBecomeWhite();
}


void loop() {
}


/*
 * This is just a function to test the buggy without the Ultrasonic sensor.
 */
void start(){
  while(true){
    int lSensorValue = analogRead(lSensor);
    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
    int rSensorValue = analogRead(rSensor);
    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
    
    if(rSensorValue < 100 && lSensorValue < 100){
      forward();
      logic1 = true;
    }else if(rSensorValue < 100 && lSensorValue > 100){
      turnRight();
      if(logic1 == true)
        logic2 = true;
    }else if(rSensorValue > 100 && lSensorValue < 100){
      turnLeft();
      if(logic1 == true)
        logic2 = true;
    }else if(rSensorValue > 100 && lSensorValue > 100){
      forward();
      if(logic1 == true)
        logic2 = true;
    }
    if(logic1 == true && logic2 == true){
      logic1 = false;
      logic2 = false;
      intersectionCounter++;
//      Serial.println(intersectionCounter);
    }
    if(intersectionCounter == 4){
      break;
    }
    
  }
  stopMoving();
  rotateTillBothBecomeWhite();
}



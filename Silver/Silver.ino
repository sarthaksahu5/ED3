/*
 * ED3 Final Project
 * @author: Sarthak Sahu, Santosh Gupta, Sanat Kumar Jain
 */
/*
 * Upload this code to buggy1
 */
#include <NewPing.h>

int TRIGGER = 13;
int ECHO = 12;
int threshold = 100;
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
  pinMode(lSensor, INPUT);
  pinMode(rSensor, INPUT);
  pinMode(motorRF, OUTPUT);
  pinMode(motorLF, OUTPUT);
  pinMode(motorLB, OUTPUT);
  pinMode(motorRB, OUTPUT);
  start();
  //start1();
}

void forward(){  
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRB, LOW);
  digitalWrite(motorRF, HIGH);
  digitalWrite(motorLF, HIGH);
//  delay(2);
//  stopMoving();
//  delayMicroseconds(20);
}

void turnRight(){
  digitalWrite(motorRF, LOW);
  digitalWrite(motorLF, HIGH);
//  delay(2);
//  stopMoving();
//  delayMicroseconds(20);
  
}

void turnLeft(){
  digitalWrite(motorRF, HIGH);
  digitalWrite(motorLF, LOW);
//  delay(2);
//  stopMoving();
//  delayMicroseconds(20);
}

void stopMoving(){
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRB, LOW);
  digitalWrite(motorLF, LOW);
  digitalWrite(motorRF, LOW);
}

void park(){
    while(true){
    int lSensorValue = analogRead(lSensor);
    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
    int rSensorValue = analogRead(rSensor);
    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
    
    if(rSensorValue < threshold && lSensorValue < threshold){
      stopMoving();
      Serial.println("S");
      while(true){
      }
    }else if(rSensorValue < threshold && lSensorValue > threshold){
      turnRight();
    }else if(rSensorValue > threshold && lSensorValue < threshold){
      turnLeft();
    }else if(rSensorValue > threshold && lSensorValue > threshold){
      forward();
    }
  }
}
/*
* Change this function accordingly for gold task.
* make leftRotateAtIntersection() for gold task.
*/
void rightRotateAtIntersection(){
  logic1 = false;
  logic2 = false;
  stopMoving();
  while(true){
    int lSensorValue = analogRead(lSensor);
    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
    int rSensorValue = analogRead(rSensor);
    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);

    if(lSensorValue < threshold && rSensorValue < threshold && !logic1){
      digitalWrite(motorLF,HIGH);
      digitalWrite(motorRB,HIGH);
      logic1 = true;
    }else if(rSensorValue > threshold && logic1){
      digitalWrite(motorLF,HIGH);
      digitalWrite(motorRB,HIGH);
      logic2 = true;  
    }
//    else if(lSensorValue < threshold && rSensorValue > threshold){
//      digitalWrite(motorLF,HIGH);
//      digitalWrite(motorRB,HIGH);
//      logic1 = true;
//    }
//    else if(lSensorValue > threshold && rSensorValue > threshold){
//      stopMoving();
//      logic2 = true;
//    }
    if(logic1 == true && logic2 == true){
      logic1 = false;
      logic2 = false;
      break;
    }
    
  }
}

//void rotateTillBothBecomeWhite(){
//  logic1 = false;
//  logic2 = false;
//  while(true){
//    int lSensorValue = analogRead(lSensor);
//    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
//    int rSensorValue = analogRead(rSensor);
//    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
//    
//    if(lSensorValue > 100 && rSensorValue > 100){
//      break;
//    }
//    digitalWrite(motorRF, HIGH);
//    digitalWrite(motorLB, HIGH);
//  }
//  digitalWrite(motorLB, LOW);
//  digitalWrite(motorRB, LOW);
//  //rotate till sensors allign perfectly.
//  while(true){
//    int lSensorValue = analogRead(lSensor);
//    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
//    int rSensorValue = analogRead(rSensor);
//    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
//    
//    digitalWrite(motorRF, HIGH);
//    digitalWrite(motorLB, HIGH);
//
//    if(lSensorValue < 100 && rSensorValue > 100 && !logic1){
//      logic1 = true;
//    }
//    if(lSensorValue > 100 && rSensorValue > 100 && logic1){
//      logic2 = true;
//    }
//    if(logic1 == true && logic2 == true){
//      break;  
//    }
//  }
//  digitalWrite(motorLB, LOW);
//  digitalWrite(motorRB, LOW);
//  park();
//}


void rotateTillBothBecomeWhite(){
  logic1 = false;
  logic2 = false;
  while(true){
    int lSensorValue = analogRead(lSensor);
    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
    int rSensorValue = analogRead(rSensor);
    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
    
    if(lSensorValue >threshold && rSensorValue >threshold){
      break;
    }
    digitalWrite(motorRF, HIGH);
    digitalWrite(motorLB, HIGH);
  }
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRB, LOW);
//  rotate till sensors allign perfectly.
  while(true){
    int lSensorValue = analogRead(lSensor);
    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
    int rSensorValue = analogRead(rSensor);
    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
    
    digitalWrite(motorRF, HIGH);
    digitalWrite(motorLB, HIGH);

    if(lSensorValue <threshold && rSensorValue >threshold && !logic1){
      logic1 = true;
    }
    if(lSensorValue >threshold && rSensorValue >threshold && logic1){
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

void slowForward(){
  digitalWrite(motorLB, LOW);
  digitalWrite(motorRB, LOW);
  digitalWrite(motorRF, HIGH);
  digitalWrite(motorLF, HIGH);
  delay(2);
  stopMoving();
  delay(3);
  
}

void slowLeft(){
  digitalWrite(motorRF, HIGH);
  digitalWrite(motorLF, LOW);
  delay(2);
  stopMoving();
  delay(3);
  
}


void slowRight(){
  digitalWrite(motorLF, HIGH);
  digitalWrite(motorRF, LOW);
  delay(2);
  stopMoving();
  delay(3);
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
    
    if(endTime >=1000){
      distance = sonar.ping_cm();
      if(distance < 20 && logic1 == false){
        stopMoving();
        delay(1000);
        logic1 = true;
      }
      
      if(sonar.ping_cm() >threshold && logic1 == true){
        logic2 = true;
      }
      if(logic1 == true && logic2 == true){
        logic1 = false;
        logic2 = false;
        obstacleCounter++;  
      }
      endTime = 0;
    }
    if(rSensorValue <threshold && lSensorValue <threshold){
      // rightRotateAtIntersection();
      forward();
    }else if(rSensorValue <threshold && lSensorValue >threshold){
      turnRight();
    }else if(rSensorValue >threshold && lSensorValue <threshold){
      turnLeft();
    }else if(rSensorValue >threshold && lSensorValue >threshold){
      forward();
    }
    if(obstacleCounter == 9){
      break;
    }
    endTime++;
  }
  while(true){
    int lSensorValue = analogRead(lSensor);
    lSensorValue = map(lSensorValue, 0, 1023, 0, 255);
    int rSensorValue = analogRead(rSensor);
    rSensorValue = map(rSensorValue, 0, 1023, 0, 255);
    
    if(rSensorValue < threshold && lSensorValue <threshold){
      //rightRotateAtIntersection();
      forward();
      logic1 = true;
    }else if(rSensorValue <threshold && lSensorValue >threshold){
      turnRight();
      if(logic1 == true)
        logic2 = true;
    }else if(rSensorValue >threshold && lSensorValue <threshold){
      turnLeft();
      if(logic1 == true)
        logic2 = true;
    }else if(rSensorValue >threshold && lSensorValue >threshold){
      forward();
    }
    if(logic1 == true && logic2 == true){
      logic1 = false;
      logic2 = false;
      intersectionCounter++;
    }
    if(intersectionCounter == 2){
      break;
    }
  }
  /*
   * Vary the delay according to sensitivity of the Sensor.
   * Comment out the delay if not needed at all.
   */
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
    
    if(rSensorValue <threshold && lSensorValue <threshold){
      //rightRotateAtIntersection();
      slowForward();
      logic1 = true;
    }else if(rSensorValue <threshold && lSensorValue >threshold){
      slowRight();
      if(logic1 == true)
        logic2 = true;
    }else if(rSensorValue >threshold && lSensorValue <threshold){
      slowLeft();
      if(logic1 == true)
        logic2 = true;
    }else if(rSensorValue >threshold && lSensorValue >threshold){
      slowForward();
      if(logic1 == true)
        logic2 = true;
    }
    if(logic1 == true && logic2 == true){
      logic1 = false;
      logic2 = false;
      intersectionCounter++;
//      Serial.println(intersectionCounter);
    }
    if(intersectionCounter == 1){
      break;
    }
  }
  intersectionCounter = 0;
  start1();
}

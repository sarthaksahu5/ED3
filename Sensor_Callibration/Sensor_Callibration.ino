int sensor1 = 0;
int sensor2 = 5;

int val1;
int val2;

void setup()
{
Serial.begin(9600);
pinMode (sensor1, INPUT);
pinMode (sensor2, INPUT);
}
void loop()
{
val1 = analogRead(sensor1);
val2 = analogRead(sensor2);
Serial.println("First Sensor");
Serial.println(val1);
Serial.println("Second Sensor");
Serial.println(val2);
delay (1000);
}

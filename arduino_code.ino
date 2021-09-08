//Include servo library
#include <Servo.h>
Servo servo;     
int trigPin = 6;  // Trigger Input Pin 
int echoPin = 5;  // Echo Output Pin
int servoPin = 7; // Signal to servo mototr
long duration, distance, average;   
long aver[3];   //array for average


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0); //Initailly, the lid is closed or motor is at zero degree.
    delay(100);
    servo.detach(); 
} 

void measure() {  
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);  //Calculate time for which echopin is high or time taken by waves to travel
distance = (duration/2)*0.034;     //speed of sound in cm/microseconds = 0.034
}
void loop() { 
  for (int i=0;i<=2;i++)
  {
    measure();               
    aver[i]=distance;            
    delay(10);              //delay between measurements
  }
 distance=(aver[0]+aver[1]+aver[2])/3;  //average distance  

if ( distance<15 ) {    //Change distance as per your need
  servo.attach(servoPin);
  delay(1);
  servo.write(0);  
  digitalWrite(10,HIGH);
  delay(00);       
  servo.write(180);    
  delay(3000);
  servo.write(0);
  digitalWrite(10,LOW);
  }
Serial.print("Distance:");
Serial.println(distance);  //print distance on serial monitor
}

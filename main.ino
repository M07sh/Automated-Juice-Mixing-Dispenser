#include <Wire.h> 
#include <Servo.h> 
int Temperature;
int TEMP;
int LED = 10;
int LED1 = 45;
int pinStep = 46;
int pinDir = 47;
int oneRevStep =400;
int speed = 1 ;
int x;
int i;
int r;
int pumpA = 52;
int pumpA1 = 53;
int pumpB = 50;
int pumpB1 = 51;
int servoPin = 6;
int servoPin1 = 12;
int pwm = 3;
int pwm1 = 5;
int button = 7;
int button1 = 2;
int  buttonState1;
int  buttonState2;
Servo servo; 
Servo servo1;
int save; 
char save1; 

void setup() {
  
  Serial.begin(9600);
   pinMode(pumpA, OUTPUT);
   pinMode(pumpA1, OUTPUT);
   pinMode(pumpB, OUTPUT);
   pinMode(pumpB1, OUTPUT);

  pinMode (pinStep, OUTPUT);
  pinMode (pinDir, OUTPUT);
   
   pinMode(pwm, OUTPUT);
   pinMode(pwm1, OUTPUT);
   pinMode(button, INPUT);
    pinMode(button1, INPUT);
   servo.attach(servoPin); 
   servo1.attach(servoPin1); 
   pinMode(LED,OUTPUT);
   pinMode(LED1,OUTPUT);
}

void loop() {
  digitalWrite (LED , HIGH);
    TEMP = analogRead(A1);
    Temperature = (TEMP*5.0*100)/1023.0;
    buttonState1 = digitalRead(button);
    buttonState2 = digitalRead(button1);
  if (Serial.available()){
    char qtread = Serial.read();
     int qttime = Serial.parseInt();
     save = qttime;
     save1 = qtread ;
     
    
  // step one revolution  in one direction:
  if ((qtread == 'r') ||    (qtread == 'g') || (qtread == 'd') )                        
    {
     servo1.write(180);
     delay(1000);               
     servo.write(0);               
    delay(500);             
   servo.write(90);  
     delay(500);                      
    servo.write(180);  
     delay(2000); 
     servo.write(0);  
     delay(500);
    }

  }
       if (( buttonState1 == LOW) && (save1 == 'r')&&( buttonState2 == LOW))
       {
     delay (2000);
     
     servo1.write(180);               
    delay(2000);             
   servo1.write(80);  
     delay(2000);                      
     
      digitalWrite(pinDir, LOW);
  for (i = 0; i < oneRevStep; i++)
  {
    digitalWrite(pinStep, HIGH);
    delay(speed);
    digitalWrite(pinStep, LOW);
    delay(speed);
}
   digitalWrite(pumpA,HIGH);
   digitalWrite(pumpA1,LOW);
     digitalWrite(pumpB,LOW);
   digitalWrite(pumpB1,LOW);
   analogWrite(pwm,255);
    
    delay((100-save)*110);
     digitalWrite(pumpA,LOW);
   digitalWrite(pumpA1,LOW);
    digitalWrite(pumpB,HIGH);
   digitalWrite(pumpB1,LOW);
   analogWrite(pwm1,255);
    delay(save*110);
    digitalWrite(pumpB,LOW);
    analogWrite(pwm,0);
    analogWrite(pwm1,0);
    delay(3000); 
    
    servo1.write(0);  
    delay(3000); 
    
  }  
  if (( buttonState1 == LOW) && (save1 == 'd')&&( buttonState2 == LOW))
       {
     delay (2000);
     servo1.write(180);               
    delay(500);             
   servo1.write(80);  
     delay(2000);                      
     
     digitalWrite(pinDir, LOW);
  for (i = 0; i < oneRevStep; i++)
  {
    digitalWrite(pinStep, HIGH);
    delay(speed);
    digitalWrite(pinStep, LOW);
    delay(speed);
}
   digitalWrite(pumpA,HIGH);
   digitalWrite(pumpA1,LOW);
     digitalWrite(pumpB,LOW);
   digitalWrite(pumpB1,LOW);
   analogWrite(pwm,170);
    
    delay((100-save)*110);
     digitalWrite(pumpA,LOW);
   digitalWrite(pumpA1,LOW);
    digitalWrite(pumpB,HIGH);
   digitalWrite(pumpB1,LOW);
   analogWrite(pwm1,170);
    delay(save*110);
    digitalWrite(pumpB,LOW);
    analogWrite(pwm,0);
    analogWrite(pwm1,0);
    delay(3000); 
   
    servo1.write(0);  
     delay(3000); 
    
  }
  if (( buttonState1 == LOW) && (save1 == 'g')&&( buttonState2 == LOW))
       {
     delay (2000);
     servo1.write(180);               
    delay(500);             
   servo1.write(80);  
     delay(2000);                      
     
     digitalWrite(pinDir, LOW);
  for (i = 0; i < oneRevStep; i++)
  {
    digitalWrite(pinStep, HIGH);
    delay(speed);
    digitalWrite(pinStep, LOW);
    delay(speed);
}
   digitalWrite(pumpA,HIGH);
   digitalWrite(pumpA1,LOW);
     digitalWrite(pumpB,LOW);
   digitalWrite(pumpB1,LOW);
   analogWrite(pwm,110);
    
    delay((100-save)*100);
     digitalWrite(pumpA,LOW);
   digitalWrite(pumpA1,LOW);
    digitalWrite(pumpB,HIGH);
   digitalWrite(pumpB1,LOW);
   analogWrite(pwm1,110);
    delay(save*100);
    digitalWrite(pumpB,LOW);
    analogWrite(pwm,0);
    analogWrite(pwm1,0);
    delay(3000); 
   
    servo1.write(0);  
     delay(3000); 
    
  }    
  if (( buttonState1 == HIGH) &&  (buttonState2 == HIGH))
  {
    delay(3000);
     servo1.write(180);
  }
  if (Temperature >= 30){
    digitalWrite (LED , LOW);
    digitalWrite (LED1 , HIGH);
 }
 else if (Temperature < 30) {
  digitalWrite (LED , HIGH);
  digitalWrite (LED1 , LOW);
  
 }
  
 
  }
   
  
    

   
  // step one revolution in the other direction:
    
    

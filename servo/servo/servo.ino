
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 

int val;    
//declaramos las variables para los pin a utilizar
 int led=13;
 int led2=12;
 int led3=11;
void setup() 
{ 
  77declaramos el modo en utilizar los pin
    pinMode(led, OUTPUT); 
      pinMode(led2, OUTPUT); 
        pinMode(led3, OUTPUT); 
  Serial.begin(9600);//inicializamos el puerto serial
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 

} 
 
void loop() 
{ 
  for(int i=0;i<180;i++){
   myservo.write(i); //se le manda los calores a el servo
  delay(2000);
  
  if(i<=45){//si el angulo es menor a 45 se enciende el foco1
  digitalWrite(led, HIGH);  
  delay(1000);             
  digitalWrite(led, LOW);  
  delay(1000); 
  
  }
   if(i>45 && i<=90){//si el angulo esta entre  45 y 90 se enciende el foco2
  digitalWrite(led2, HIGH);  
  delay(1000);             
  digitalWrite(led2, LOW);  
  delay(1000); 
  
  }
   if( i>90){//si el angulo es mayor a 90 enciende el foco3
  digitalWrite(led3, HIGH);  
  delay(1000);             
  digitalWrite(led2, LOW);  
  delay(1000); 
  
  }
  i+=4;
  int valor=myservo.read();


Serial.println(valor);
  }

} 


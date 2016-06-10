#include <Ultrasonic.h>//libreria para ultrasonido
#include <IRremote.h>// Libreria para usar receptor I.R:
//declarando funciones a utilizar
void autonomo();
void control();//funcion del control

int RECV_PIN = 11;//Se define el pin de entrada de arduino
IRrecv irrecv(RECV_PIN);
decode_results results;

//definiendo pines para ultrasonido
#define PINO_TRG  7
#define PINO_ECHO 4

Ultrasonic ultrasonic(PINO_TRG, PINO_ECHO);

int led = 13;             //Led que se activara con el sensor
//declaracio de los pin para los motores
int izqA = 5; 
int izqB = 6; 
int derA = 9; 
int derB = 10; 
int vel = 255;            // Velocidad de los motores (0-255)


void setup()  { 
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
//declaracion de modo de los pin
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);


  pinMode(2,  OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);//iniciamos puerto serial
  irrecv.enableIRIn();//inicia recepcion
  

  //INTERRUPCION
  attachInterrupt( 0, control, FALLING);
 } 
 
void loop()  { 

   
  //autonomo();
  control();

}

void autonomo(){

               
            
     //Variable para almacenar distancia en centimetros
      float cmMsec;

      //Lee los valores del ultrsonico
      long microsec = ultrasonic.timing();
      
      //Capturamos distancia
      cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
      delay(50);
      Serial.println(cmMsec);
      
  if(cmMsec <= 10 && cmMsec >=2){
        digitalWrite(led, HIGH);              //Si detecta obstaculo enciende el led

        analogWrite(derB, 0);                 //Paramos los motores
        analogWrite(izqB, 0);
        analogWrite(derA, 0);
        analogWrite(izqA, 0);
        delay(200);

        analogWrite(derB, vel);               //Reversa
        analogWrite(izqB, vel);
        delay(2000);

        analogWrite(derB, 0);                 //Giramos
        analogWrite(izqB, 0);
        analogWrite(derA, 0);
        analogWrite(izqA, vel);
        delay(1500);

        digitalWrite(led, LOW);//se apaga led

        }else{
            analogWrite(derB, 0);     
            analogWrite(izqB, 0); 
            analogWrite(derA, vel);  
            analogWrite(izqA, vel); 
          }
  
  }

  void control(){
     if(irrecv.decode(&results)){
  Serial.println(results.value);//imprimir en el puerto serial los valores
  irrecv.enableIRIn();
     }
    
  if(results.value == 3261853764){           // Boton desplazar al Frente
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, vel);  
      analogWrite(izqA, vel);  
 }
  if(results.value == 1972149634){          // Boton IZQ 
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);  
      analogWrite(izqA, vel);   
      delay(800);
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);    
      analogWrite(izqA, 0); 
  }
  if(results.value == 4105841032){         // Boton Parar
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);    
      analogWrite(izqA, 0); 
  }
  if(results.value == 1400905448){          // Boton DER
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, 0);
       analogWrite(derA, vel);  
       delay(800);
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);    
      analogWrite(izqA, 0);  
  } 
  
  if(results.value == 3693766967){          // Boton Reversa
       analogWrite(derA, 0);    
       analogWrite(izqA, 0);
       analogWrite(derB, vel);  
       analogWrite(izqB, vel);  
   
  }

//Subir marcha
  if(results.value == 1595074756){
    if(vel <255)
    {
      vel = 255;
      }
       analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, vel);  
      analogWrite(izqA, vel); 
    }

//Bajar Marcha
      if(results.value == 412973352){
    if(vel =255)
    {
      vel = 128;
      }
       analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, vel);  
      analogWrite(izqA, vel); 
    }
     }
 
 

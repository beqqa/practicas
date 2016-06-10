
 

void setup() {                
  //declarando el modo de los pines a utilizar
pinMode(9,OUTPUT);  
pinMode(10,OUTPUT); 
pinMode(11,OUTPUT); 
pinMode(12,OUTPUT); 
pinMode(13,OUTPUT); 
}


void loop() {
  //declarando for para encender led dinamicamente
  //encediendo focos de derecha a izquierda
  for(int i=9;i<=13;i++){
  
   digitalWrite(i, HIGH);
   delay(1000);               
  digitalWrite(i, LOW);   
  delay(1000);       
  }
  //encendiendo focos de izquierda a derecha
  for(int i=13;i<=9;i--){
  
   digitalWrite(i, HIGH);
   delay(1000);               
  digitalWrite(i, LOW);   
  delay(1000);       
  }
               
}

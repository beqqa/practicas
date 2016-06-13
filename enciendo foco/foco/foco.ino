//declaramos como led el pin a utilizar
int led = 13;


void setup() {                
//declaramos el modo del pin
  pinMode(led, OUTPUT);     
}


void loop() {
  digitalWrite(led, HIGH);   //encendemos foco
  delay(1000);            //se mantiene encendido por un minuto
  digitalWrite(led, LOW);    //se apaga foco
  delay(1000);              //se apaga por un segundo
}

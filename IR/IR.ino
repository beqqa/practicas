#include <IRremote.h>

//#include <IRremoteInt.h>

int RECV_PIN = 7; //define input pin on Arduino
int led = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value );
    irrecv.resume(); // Receive the next value
  }
  if (results.value ==4294967295) //Tecla de arriba
  {
    digitalWrite(led, HIGH);

  }
  if (results.value == 284106975) 
  {
  digitalWrite(led, LOW);
  }
}





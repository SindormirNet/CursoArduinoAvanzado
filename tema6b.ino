#include <TimerOne.h>
#define PARPADEO_OK   10000
#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
  Timer1.initialize(100);       // Inicializamos Temporizador 1 a 100us.
  Timer1.attachInterrupt(parpadea);   // Función asociada al desbordamiento.
}

void parpadea() {
  static unsigned long contador=0;
  contador++;
  if (contador > PARPADEO_OK){
    contador=0;
    digitalWrite(LED, !digitalRead(LED));
  }
}

void loop() {
  for (int i = 0; i < 1023; i++) {
    Timer1.pwm(9, i);
    delay(2);
  }
} 

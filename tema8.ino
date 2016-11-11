#include <TimerOne.h>

#define PULSO() digitalWrite(TRIGGER, HIGH); delayMicroseconds(10); digitalWrite(TRIGGER, LOW) 	// Macro para mandar el pulso inicial
#define ECHO 8			// Pin para recibir el pulso de eco
#define TRIGGER 9			// Pin para enviar el pulso de disparo
#define LED 13
 
void setup() {
  pinMode(TRIGGER, OUTPUT);
  pinMode(LED, OUTPUT);
  Timer1.initialize();	            // Inicializamos Temporizador 1 a 1s.
  Timer1.attachInterrupt(parpadea);	// Función asociada al desbordamiento. 
}

void parpadea() {
  digitalWrite(LED, !digitalRead(LED));
}
 
void loop() {
  unsigned int tiempo, distancia;
  PULSO();	//Enviamos pulso
  tiempo = pulseIn(ECHO,HIGH); // Medimos el tiempo que tarda en volver el echo
  distancia= tiempo/58; 	 // El sonido tarda 29uS en recorrer un cm.
  // Cambiamos la frecuencia del led en función de la distancia
  Timer1.setPeriod(map(distancia,0,300,10000,1000000)); // Ajustamos Timer1
  delay(60);  // Y dejamos tiempo antes de emitir un nuevo pulso
}

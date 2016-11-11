#include <Metro.h>

#define PARPADEO_OK 	1000	// 1 segundo 
#define PARPADEO_ERR 	50	// 50 ms
#define LED 13

boolean estado = LOW;
Metro MetroEstado = Metro(PARPADEO_OK); // Creamos objeto tipo Metro

void setup() {
  pinMode(LED,OUTPUT);
  digitalWrite(LED,estado);
  Serial.begin(9600);
}

void loop() {
  if (MetroEstado.check()) {
    if (estado==HIGH){ 
	estado=LOW;
    }
    else { 
	estado=HIGH;   
    }
    digitalWrite(LED,estado);
  }
    if (Serial.available()) {
    if (Serial.read() == 'x')
      MetroEstado.interval(PARPADEO_ERR);
    else
      MetroEstado.interval(PARPADEO_OK);
  }
}

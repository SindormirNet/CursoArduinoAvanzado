boolean valido = false;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (valido) digitalWrite(LED_BUILTIN, HIGH);
}

void serialEvent() {
	static char comando[3] = "";
	static unsigned char estado = 0;
	switch (estado) {
	case 0: //recibir primer carácter
			comando[0] = Serial.read();
			estado = 1;
		break;
	case 1: //recibir segundo carácter
			comando[1] = Serial.read();
			estado = 2;
		//break;
	case 2:
		if ((comando[0] == 'o') && ((comando[1] == 'k'))) valido = true;
		estado = 0;
	}
}


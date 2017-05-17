void setup() {
  Serial.begin(9600);
  DDRD = 0xFF;
}

void loop() {
  PIND = 0xFF;
  delay(1000);
}

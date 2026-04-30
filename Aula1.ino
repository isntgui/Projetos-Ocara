// ligando e desligando o led

#define led_vermelho 10

void setup() {
  pinMode(led_vermelho, OUTPUT);
}

void loop() {
  digitalWrite(led_vermelho, HIGH);
  delay(1000);
  digitalWrite(led_vermelho, LOW);
  delay(1000);
}
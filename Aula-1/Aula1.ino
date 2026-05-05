// ligando e desligando o led

#define led_vermelho 10

void setup() {
  pinMode(led_vermelho, OUTPUT);        // led é uma saída de dados, então é output
}

void loop() {
  digitalWrite(led_vermelho, HIGH);    // ascender o led utilizando o HIGH
  delay(1000);                         // espera de um segundo (1000 ms) com o led ligado
  digitalWrite(led_vermelho, LOW);     // desligar um led utilizando o LOW
  delay(1000);                         // espera de um segundo (1000 ms) com o led desligado
}

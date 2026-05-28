#define pino_vermelho 8
#define pino_amarelo 9
#define pino_verde 10

void setup() {
  pinMode(pino_vermelho, OUTPUT);
  pinMode(pino_amarelo,  OUTPUT);
  pinMode(pino_verde,    OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'H') {
      digitalWrite(pino_vermelho, HIGH);
    } else if (command == 'h') {
      digitalWrite(pino_vermelho, LOW);
    } else if (command == 'A') {
      digitalWrite(pino_amarelo, HIGH);
    } else if (command == 'a') {
      digitalWrite(pino_amarelo, LOW);
    } else if (command == 'Y') {
      digitalWrite(pino_verde, HIGH);
    } else if (command == 'y') {
      digitalWrite(pino_verde, LOW);
    } else if (command == 'G') {
      digitalWrite(pino_vermelho, HIGH);
      digitalWrite(pino_amarelo, HIGH);
      digitalWrite(pino_verde, HIGH);
    } else if (command == 'g') {
      digitalWrite(pino_vermelho, LOW);
      digitalWrite(pino_amarelo, LOW);
      digitalWrite(pino_verde, LOW);
    }
  }
}

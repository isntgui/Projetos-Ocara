#define led 13

char command = 0;

void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.print("Comando recebido via Bluetooth");
    Serial.println(command);
    if (command == '1') {
      digitalWrite(led, HIGH);
      Serial.println("led ligado!");
    } else if (command == '0') {
      digitalWrite(led, LOW);
      Serial.println("led desligado!");
    }
  }
}

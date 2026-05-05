#define led_red 10
#define led_green 7
#define led_blue 4

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  onRed();
  delay(1000);
  onGreen();
  delay(1000);
  onBlue();
  delay(1000);
  // ==============
  onYellow();
  delay(1000);
  onPurple();
  delay(1000);
  // =============
  onMagenta();
  delay(1000);
  // =============
  onWhite();
  delay(1000);

}

void onRed() {
  digitalWrite(led_red, HIGH);
  digitalWrite(led_green, LOW);
  digitalWrite(led_blue, LOW);
}

void onGreen() {
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, HIGH);
  digitalWrite(led_blue, LOW);
}

void onBlue() {
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, LOW);
  digitalWrite(led_blue, HIGH);
}

// ==================================

void onYellow() {
  digitalWrite(led_red, HIGH);
  digitalWrite(led_green, HIGH);
  digitalWrite(led_blue, LOW);
}

void onPurple() {
  digitalWrite(led_red, HIGH);
  digitalWrite(led_green, LOW);
  digitalWrite(led_blue, HIGH);
}

// =================================

void onMagenta() {
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, HIGH);
  digitalWrite(led_blue, HIGH);
}

// =================================

void onWhite() {
  digitalWrite(led_red, HIGH);
  digitalWrite(led_green, HIGH);
  digitalWrite(led_blue, HIGH);
}

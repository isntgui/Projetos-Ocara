#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define pinoTrig 10
#define pinoEcho 9

LiquidCrystal_I2C lcd(0x27, 16, 2);

float pingTime;
float distance;
float speed_sound = 343.0;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("Dist. do Objeto:");
}

void loop() {
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);
  pingTime = pulseIn(pinoEcho, HIGH);
  distance = (pingTime / 2.0) * (speed_sound / 10000.0);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");
  delay(1000);
}

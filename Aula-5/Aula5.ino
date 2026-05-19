#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 10
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE); // (pino, tipo)

bool texto = true;

void setup() {
  // ==============  LCD  ==============
  lcd.init();
  lcd.backlight();

  // ============== DHT11 ==============
  dht.begin();

  // ============== DEBUG ==============

  Serial.begin(9600);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.println(String(temperature) + " " + String(humidity));

  if (isnan(temperature) || isnan(humidity)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro ao ler DHT");
    texto = true;

  } else {
    if (texto) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp.:");
      lcd.setCursor(0, 1);
      lcd.print("Umid.:");
      texto = false;
    }

    String info1 = String(temperature, 1) + " C";
    String info2 = String(humidity, 1) + " %";

    lcd.setCursor(16 - info1.length(), 0);
    lcd.print(info1);
    lcd.setCursor(16 - info1.length(), 1);
    lcd.print(info2);
      
  }
  delay(3000);
}

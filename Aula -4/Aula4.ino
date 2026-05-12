#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String parts[] = {"Industria 4.0!", "Seu Nome"};
int words = sizeof(parts) / sizeof(parts[0]);

void setup() {
  lcd.init();
  lcd.setBacklight(HIGH);
}

void loop() {

  lcd.clear();

  for (int i = 0; i < words; i++) {
    
    int sz = parts[i].length();

    if (!i) delay(1000);

    for (int j = 0; j < sz; j++) {

      int pos = (16 - sz) / 2;

      lcd.setCursor(pos + j, i);
      lcd.print(parts[i][j]);
      delay(50);

    }

    delay(100);
  }

}

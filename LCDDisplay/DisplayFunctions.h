#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//#include "SensorFunctions.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void LCDSetup() {
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
}

void LCDLoop() {
//  if(isnan (Temperature) || isnan (Humidity)) {
//    lcd.setCursor(0,0);
//    lcd.print("Failed");
//  }
//  else {
    lcd.setCursor(0,0);
    lcd.print("Temp: ");
//    lcd.print(Temperature);
    lcd.print((char)223);
    lcd.print("C");

    lcd.setCursor(0,1);
    lcd.print("Humidity: ");
//    lcd.print(Humidity);
    lcd.print("%");
  
}

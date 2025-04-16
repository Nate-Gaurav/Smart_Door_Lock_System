#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  lcd.setCursor(0, 0);             // Set cursor to first column, first row
  lcd.print("Sa Re ga ma pa");      // Print 
  lcd.setCursor(0, 1);
  lcd.print("dha ni sa");

}

void loop() {
  // Nothing in the loop for this example
}

/* Brausteuerung
Author: Oliver Milde, Steffen L
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


/* Pins */
int PinRelais1 = 7;

const char EIN = LOW;
const char AUS = HIGH;


void setup() {
  
  lcd.begin(20,4);
  lcd.backlight();

  pinMode(PinRelais1, OUTPUT);
  
}

void loop() {

      //digitalWrite(PinRelais1, EIN);
      
  float temperature = getTemp();
  
  lcd.setCursor(0,0);
  lcd.print("Hallo World...");
  lcd.setCursor(0,1);
  lcd.print("Hallo Steffen...");
  lcd.setCursor(0,2);
  lcd.print(temperature);
  
  lcd.setCursor(0,3);
  lcd.print("\337C");
  lcd.setCursor(19,3);
  lcd.print("X");

  delay(1000);
  //lcd.clear();
 
}

void Einmaischen(){

  
}


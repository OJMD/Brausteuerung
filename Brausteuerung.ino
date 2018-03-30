/* Brausteuerung
Author: Oliver Milde, Steffen L
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


/* Pins */
int PinRelais1 = 7;


/* Constante */
const char EIN = LOW;
const char AUS = HIGH;


/*  Sollte in eine Class gepackt werden?*/
float   Temp[] = {45,62,68,72,72,78,99};                                // Default Temperaturen 0: Einmaischen; 1: Rast 1 usw.
long    Timer[] = {900000,180000,180000,180000,180000,0,4500000};     // Default Zeiten für 0: Einmaischen; 1: Rast 1 usw.
bool    CheckTemp[] = {false,false,false,false};                           // Alle Prüfungen auf false setzen.
String  Name[] = {"Einmaischen:","1. Rast:","2. Rast:","3. Rast:", "4. Rast:", "Laeutern:","Kochen:"};


void setup() {

  Serial.begin (9600);

  lcd.begin(20,4);
  lcd.backlight();
  lcd.clear();

  pinMode(PinRelais1, OUTPUT);

  digitalWrite(PinRelais1, AUS);

}

void loop() {

  float temperature = getTemp();

  Task( 5 );
 
}

void Task(int id){

  float t_ist = getTemp();

  String ct; // Current time


  if(t_ist <= Temp[id]){
    digitalWrite(PinRelais1, EIN);
  }else{
    digitalWrite(PinRelais1, AUS);
    CheckTemp[id] = true;
    Serial.write("Check Temp 0 = True \n");
  }

  if(CheckTemp[id] == true ){
    ct = msToTime( Timer[id] - millis() );
  }else{
    ct = msToTime( Timer[id] );
  }

  if( (int)( Timer[id] - millis() ) <= 0 ){
    ct = "0:00:00";    
  }
  
  // Erste Zeile .....
  lcd.setCursor(0,0);
  lcd.print( Name[id] );
  lcd.setCursor(13,0);
  lcd.print( Temp[id] + String("\337C") );
  
  // Zweite Zeile .....
  lcd.setCursor(0,2);
  lcd.print("Dauer:");
  lcd.setCursor(12,2);
  lcd.print( ct  );

// Vierte Zeile .....
  lcd.setCursor(13,3);
  lcd.print( t_ist + String("\337C")  );

}

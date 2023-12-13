#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
char value;

void lcd_standby(void){
  lcd.setCursor(0,0);
  lcd.print("Smart Trashbin  ");
  lcd.setCursor(0,1);
  lcd.print("TEAM 2 - GPT    ");
}
void setup(){
  mySerial.begin(38400);
  lcd.begin(16, 2);
  lcd_standby();
}

void loop()        
{
  if(mySerial.available()>0){ //
    value=mySerial.read();
    if(value=='c'){
      lcd.setCursor(0,0);
      lcd.print("Detected CAN    ");
      lcd.setCursor(0,1);
      lcd.print("Open Trashbin 1 ");
      delay(9000);
    }
    if(value=='p'){
      lcd.setCursor(0,0);
      lcd.print("Detected PLASTIC");
      lcd.setCursor(0,1);
      lcd.print("Open Trashbin 2 ");
      delay(9000);
    }
    if(value=='v'){
      lcd.setCursor(0,0);
      lcd.print("Detected VINYL  ");
      lcd.setCursor(0,1);
      lcd.print("Open Trashbin 3 ");
      delay(9000);
    }
    lcd_standby();
  }
}


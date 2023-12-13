#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial mySerial(2, 3);
Servo bin1, bin2, bin3;
char value;
void setup(){
  mySerial.begin(19200);
  bin1.attach(9);
  bin2.attach(10);
  bin3.attach(11);
  bin1.write(0);
  bin2.write(0);
  bin3.write(0);
}
void loop()        
{
  int pos;
  if(mySerial.available()>0){
    value=mySerial.read();
    if(value=='c'){
      Serial.println("can");
      for(pos=0; pos<=90; pos++){
        bin1.write(pos);
        delay(5);
      }
      delay(9000);
      bin1.write(0);
      delay(1000);
    }
    if(value=='p'){
      Serial.println("plastic");
      for(pos=0; pos<=90; pos++){
        bin2.write(pos);
        delay(5);
      }
      delay(9000);
      bin2.write(0);
      delay(1000);
    }
    if(value=='v'){
      Serial.println("vinyl");
      for(pos=0; pos<=90; pos++){
        bin3.write(pos);
        delay(5);
      }
      delay(9000);
      bin3.write(0);
      delay(1000);
    }
  }
}



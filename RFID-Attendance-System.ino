#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int count = 0,c=0,i; 
char RFIDtag[12]={0};
String readMsg;
char tag1[12]="4C006E6796D3";//place u r own card ids here
 char tag2[12]="4C006EF877AD";
 char tag3[12]="4C006E6CA6E8";
void setup()
 {
   Serial.begin(9600);
   lcd.begin(16,2); 
   lcd.setCursor (0,1);
   lcd.print("    ECE-C   ");
   lcd.setCursor(0,0); 
   lcd.print("  RFID Reader  ");
   delay (5000);
 }

void loop() 
{
 if(readMsg == 0)
  {                        
   lcd.setCursor(0,0);
   lcd.print(" Swipe the Card ");
   lcd.setCursor(0,1);
   lcd.print("                ");
  }
while(Serial.available()>0)
  {   

{
    count = 0;
    while (count < 12)
    {
      while (!Serial.available()) {
      }
      
      RFIDtag[count] = Serial.read();
      count++;
    }
   lcd.setCursor(0,0);
   lcd.print("Student          ");
 if(memcmp(RFIDtag,tag1,12)==0)
{
  lcd.setCursor(0,0);
   lcd.print("Student: SASI   ");//wite desired info here to print on lcd
  lcd.setCursor(0,1);
 lcd.print("14BQ1A04G1 - P");
 delay(2000);
}  
else if(memcmp(RFIDtag,tag2,12)==0)
{lcd.setCursor(0,0);
   lcd.print("Student: SAI   ");
  lcd.setCursor(0,1);
 lcd.print("14BQ1A04H1 - P");
delay(2000);
}
else if(memcmp(RFIDtag,tag3,12)==0)
{lcd.setCursor(0,0);
   lcd.print("Student: AKBAR   ");
  lcd.setCursor(0,1);
 lcd.print("15BQ5A0427 - P");
delay(2000);
}
else
{lcd.setCursor(0,1);
 lcd.print("Invalid card");
}
  }  
 
readMsg="";
delay(1000);
}
}

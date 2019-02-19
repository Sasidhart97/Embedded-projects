///////////////////////code created by///////////////////////
//////////////////////KJ's electronics//////////////////////
#include <Servo.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo myservo;
int PIR_output=6; // output of pir sensor

int buzzer=7;// buzzer pin
int pos = 0;
void setup() {
  myservo.attach(9);
pinMode(PIR_output, INPUT);// setting pir output as arduino input
lcd.begin(16, 2);
  // Print a message to the LCD.
  
  lcd.print("WELCOME!");
  Serial.println("CLEARDATA");
    Serial.println("LABEL,Date,Time,Millis,Activity");

delay(2000);
lcd.clear();

pinMode(buzzer, OUTPUT);//setting buzzer as output
Serial.begin(9600);//serial communication between arduino and pc
myservo.write(pos);
}
void loop() {
if(digitalRead(6) == HIGH) // reading the data from the pir sensor
{
  lcd.clear();
  lcd.print("Motion detected");
  Serial.println( (String) "DATA,DATE,TIME," + millis() + "," + "Motion detected " );
 delay(2000);
 for(pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
   digitalWrite(7, HIGH); // setting led to low

 
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   digitalWrite(7, LOW);
   lcd.clear();
}
else {
 lcd.setCursor(0, 1);
 lcd.print("Scanning");
 Serial.println( (String) "DATA,DATE,TIME," + millis() + "," +"Scanning");
 Serial.println();
 delay(1000);
}
}

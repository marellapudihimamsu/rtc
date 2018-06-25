#include <Wire.h> //include Wire.h library
#include "RTClib.h" //include Adafruit RTC library

RTC_DS3231 rtc; //Make a RTC DS3231 object

//Set the names of days
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int a,b;
void setup () {  
 Serial.begin(9600); 
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 //Begin the Serial at 9600 Baud
 //Print the message if RTC is not available
 if (! rtc.begin()) {
   Serial.println("Couldn't find RTC");
   while (1);
   }
 //Setup of time if RTC lost power or time is not set
 if (rtc.lostPower()) {
   //Sets the code compilation time to RTC DS3231
   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
 }
}

void loop () {
 //Set now as RTC time
 DateTime now = rtc.now();
 //Print RTC time to Serial Monitor
 Serial.print(now.year(), DEC);
 Serial.print('/');
 Serial.print(now.month(), DEC);
 Serial.print('/');
 Serial.print(now.day(), DEC);
 Serial.print(" (");
 Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
 Serial.print(") ");
 Serial.print(now.hour(), DEC);
 Serial.print(':');
 Serial.print(now.minute(), DEC);
 Serial.print(':');
 Serial.print(now.second(), DEC);
 a=now.minute();
 b=now.hour();
while(a==38&&b==7)
{ //Print RTC time to Serial Monitor'
   DateTime now = rtc.now();
 Serial.print(now.year(), DEC);
 Serial.print('/');
 Serial.print(now.month(), DEC);
 Serial.print('/');
 Serial.print(now.day(), DEC);
 Serial.print(" (");
 Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
 Serial.print(") ");
 Serial.print(now.hour(), DEC);
 Serial.print(':');
 Serial.print(now.minute(), DEC);
 Serial.print(':');
 Serial.print(now.second(), DEC);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  analogWrite(A0,150);
   a=now.minute();
    b=now.hour();
   Serial.println();
  } 
  digitalWrite(2,LOW);
  analogWrite(A0,0);
 Serial.println();
}

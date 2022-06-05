#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#define WIDTH 128
#define HEIGHT 64 
Adafruit_SSD1306 disobj(WIDTH,HEIGHT,&Wire,-1);
DHT dht(D7,DHT11);
void Temperature();
void setup() {
  Serial.begin(9600);
  pinMode(D5,OUTPUT);
  pinMode(D7,INPUT);
  // Activating internal voltage of OLED display
   if(disobj.begin(SSD1306_SWITCHCAPVCC,0x3C))
   {
        digitalWrite(D5,HIGH);
   }
   else{
     digitalWrite(D5,LOW);
   }
   dht.begin();
  Temperature();
}
void Temperature()
{
    while(1)
   {
    disobj.clearDisplay();
   disobj.setCursor(0,0);
   disobj.setTextSize(1);
   disobj.setTextColor(WHITE);

  
   float x = dht.readTemperature(false);
   disobj.print("Temperature is ");
   
   disobj.display();
   disobj.println(x);
   disobj.print("C");
   disobj.display();
   float y = dht.readHumidity();
   disobj.setCursor(0,30);
   disobj.print( "The Humidity is ");
   disobj.display();
   disobj.print(y);
   disobj.display();
   delay(1000);
   }
  //Serial.println("The value of x monitored over serial port is ");
   //Serial.printf("The value of temperature is %f",x);
   
}



void loop() {
  // put your main code here, to run repeatedly:
}
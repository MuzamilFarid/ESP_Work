//Program to generate a rectangular & circular pattern on OLED display
// Testing GIT

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_I2CDevice.h>



#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 disobj(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {

  int width_c=60;
  int height_c=60;
  int centre_coordinate_x=95;
  int centre_coordinate_y=30;
  int radius=30;
  Serial.begin(9600);

   pinMode(D5,OUTPUT);
   pinMode(D6,OUTPUT);
 // Function to activate the OLED display voltage & provide an I2C address.
 // LED glows if function call is successfull and returns TRUE.
  if(disobj.begin(SSD1306_SWITCHCAPVCC,0x3C))
  {
       digitalWrite(D5,HIGH);  
  }
  else {

      digitalWrite(D5,LOW);
  }

disobj.clearDisplay();
while(1){
  disobj.clearDisplay();
  digitalWrite(D6,LOW);
  for(int pixel_c=0; pixel_c<=30; pixel_c+=5)
{  
  delay(500); 
 disobj.drawRect(pixel_c,pixel_c,width_c,height_c,WHITE);
 disobj.drawCircle(centre_coordinate_x,centre_coordinate_y,radius,WHITE);
 disobj.display();
     width_c=width_c-10;
     height_c=height_c-10;
     radius=radius-5;
     if(width_c==10 && height_c==10)
     {
            pixel_c=0;
            width_c = 60;
            height_c=60;
            radius=30;
            break;
     }
    
}
digitalWrite(D6,HIGH);
disobj.clearDisplay();
delay(1000);


}
}

void loop()
{} 
 
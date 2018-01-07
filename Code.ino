#include <dht.h>
dht DHT;
#define DHT11_PIN 7

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h> //for this must add lib file download from Adfruit
#include <Adafruit_SSD1306.h> //for this must add lib file download from adfruit

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin (9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
  display.clearDisplay();
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);

  display.setCursor(5,0);  //OLED Display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println(DHT.temperature);

  display.setCursor(45,0);  //OLED Display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("deg C");

  display.setCursor(5,10);  //OLED Display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println(DHT.humidity);

  display.setCursor(45,10);  //OLED Display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("% Humidity");

  display.setCursor(5,20);  //OLED Display
  display.setTextSize(.5);
  display.setTextColor(WHITE);
  display.println("LIONEL TECH REVIEWS");
  
  display.display();

  delay(500);
  display.clearDisplay();
 }

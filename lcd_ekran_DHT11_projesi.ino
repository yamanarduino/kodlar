#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11 

DHT dht (DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
 lcd.begin(); 
 lcd.print("yaman birturk");
 delay(10000);
 dht.begin();
}
void loop() {
 int temp = dht.readTemperature();
 int hum = dht.readHumidity();

 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("sicaklik: ");
 lcd.print(temp);
 lcd.print(" c");
 lcd.setCursor(0,1);
 lcd.print("nem: %");
 lcd.print(hum);

 delay(5000);
}

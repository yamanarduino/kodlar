#include <SPI.h> // SPI kütüphanemizi tanımlıyoruz.
#include <MFRC522.h> // MFRC522 kütüphanemizi tanımlıyoruz.
#include <Servo.h> // Servo kütüphanemizi tanımlıyoruz.

int RST_PIN = 9 ;                          // RC522 ce reset pinini tanımlıyoruz.
int SS_PIN = 10 ;                          // RC522 yonga seçimi pinini tanımlıyoruz.
int servoPin = 8 ;                         // Servo motor pinini tanımlıyoruz.

Servo motor;                              // Servo motor için aracınız.
MFRC522 rfid (SS_PIN, RST_PIN);            // RC522 düzenleniyor.
byte ID[ 4 ] = {49,64,71,29};          // Yetkili kart ID'sini tanımlıyoruz.

void setup() {
  motor.attach(servoPin);                 // Servo motor pinini motorunu ile ilişkilendiriyoruz.
  Serial.begin( 9600 );                     // Seriyi başlatıyoruz.
  SPI.begin();                            // SPI iletişimini başlatıyoruz.
  rfid.PCD_Init();                        // RC522 modülünü başlatıyoruz.
}
 
void loop() {

if(!rfid.PICC_IsNewCardPresent())     // Yeni Kartın sergisini bekliyoruz.
    return;
if (!rfid.PICC_ReadCardSerial ())       // Kart okunmadığı zaman bekliyoruz.
    return;

  if(rfid.uid.uidByte [ 0 ] == ID[ 0 ] &&      // Okunan kart ID'si ile ID adayını test ediyoruz.
     rfid.uid.uidByte [ 1 ] == ID[ 1 ] &&
     rfid.uid.uidByte [ 2 ] == ID[ 2 ] &&
     rfid.uid.uidByte [ 3 ] == ID[ 3 ] ){
        Serial.println ( " Kapı acildi " );
        ekranaYazdir();
        motor.attach(8);                 // Servo motoru üretiriz.
        delay(4000);
        motor.write(0) ;                   // Servo motoru getiriyoruz.
        
    }
    else {                                  // Yetkisiz girişte içindeki komutlar çalıştırılır.
      Serial.println (" Yetkisiz Kart ");
      ekranaYazdir();
    }
  rfid. PICC_HaltA ();
}
void ekranaYazdir(){
  Serial.print(" ID Numarasi: ");
  for( int sayac=0; sayac<4; sayac++){
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print("  ");
  }
  
}

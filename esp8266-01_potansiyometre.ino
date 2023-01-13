 
#define REMOTEXY_MODE__ESP8266_SOFTSERIAL_POINT
#include <SoftwareSerial.h>

#include <RemoteXY.h>

 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 4444


  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 76 bytes
  { 255,13,0,0,0,69,0,16,31,2,2,0,20,8,22,11,21,8,22,11,
  1,26,31,31,79,78,0,79,70,70,0,1,0,69,7,12,12,21,32,12,
  12,136,31,0,129,0,19,39,16,6,16,40,18,6,17,100,101,196,159,101,
  114,0,7,36,40,42,20,5,46,40,20,5,2,26,2,11 };
  
 
struct {

    
  uint8_t switch_1;  
  uint8_t button_1;  
  char edit_1[11];    

    
  uint8_t connect_flag;  
} RemoteXY;
#pragma pack(pop)


#define PIN_SWITCH_1 13
#define PIN_BUTTON_1 10


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_BUTTON_1, OUTPUT);
  
  
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_BUTTON_1, (RemoteXY.button_1==0)?LOW:HIGH);
  int potasyookunan=analogRead(A0);
  dtostrf(potasyookunan,0,2,RemoteXY.edit_1);

}

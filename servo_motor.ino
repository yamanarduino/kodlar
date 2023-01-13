#include  <Servo.h> //kütüphaneyi belirledik

Servo motor; //motor değişkenini tanımladık 

void setup() {
 
}

void loop() {
motor.attach(9); //servomuza sinyali verdik
delay(3000); //süreyi yazdık
motor.write(0); //servomuza geri dön sinyalini verdik



}

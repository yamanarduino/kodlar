#define potpin A0

int deger=0;
void setup() {
  
 Serial.begin(9600);
 Serial.println("pot değer okuma başlatılıyor");

}

void loop() {
  
  deger = analogRead(potpin);
  float gerilim = (5.00/1024.00)*deger; 
  Serial.println(deger);
  delay(300);
}

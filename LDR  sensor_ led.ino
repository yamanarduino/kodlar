void setup() {
  Serial.begin(9600);

}

void loop() {
int minnosum_benim
 Serial.print("ldr degeri:");
 Serial.print("minnosum_benim");
delay(100);
if(minnosum_benim<100){
  Serial.print("ortam karanlık");
}else if(minnosum_benim<200){
  Serial.print("ortam loş");
}else if(minnosum_benim<500){
  Serial.print("aydınlık");
}else if(minnosum_benim<800){
  Serial.print("parlak");
}else {
  Serial.print("parlak");
}
}

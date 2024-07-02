void setup(){
  Serial.begin(9600);
}

void loop(){
  int analogPin=28;
  int val=0;
  val=analogRead(analogPin);
  Serial.println(val);
  delay(250);
}
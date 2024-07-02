int bf = 15;

void setup() {
  pinMode(bf, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int i = 0;
  for(i = 0; i <= 1; i++){
  digitalWrite(bf, HIGH);
  delay(250);
  digitalWrite(bf, LOW);
  delay(250);
  }
  digitalWrite(bf, HIGH);
  delay(500);
  digitalWrite(bf, LOW);
  delay(250);
}
const int echoPin = 16;
const int trigPin = 17;
void setup(){
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(15, OUTPUT);
  Serial.println("Ultrasonic sensor:");
}

void loop(){
  float distance = readSensorData();
  Serial.print(distance);
  Serial.println(" cm");
  if(distance <= 200){
    lad();
  }
  delay(400);
}

float readSensorData(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distance = pulseIn(echoPin, HIGH)/58.00;  //Equivalent to (340m/s*1us)/2
  return distance;
}


void lad(){
  int analogPin=28;
  int val=0;
  val=analogRead(analogPin);
  Serial.println("lad");
  Serial.println(val);
    if(val >= 400){
    light();
  } else {
    Serial.println("beep");
    beep();
  }
}

void beep() {
  int bf = 3;
  int l = 0;
  for(l = 0; l <= 1; l++){
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

void light() {
  
  int led = 15;
  int i = 0;
  for(i = 0; i <= 1; i++){
  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(led, LOW);
  delay(250);
  }
  Serial.println("light");
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(250);
}
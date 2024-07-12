const int echoPin = 1;  //Ultrasonic sensor US-015 Echo Pin to GP1
const int trigPin = 0;  //Ultrasonic sensor US-015 Trig Pin to GP0
const int distanceThreshold = 400;  //Ultrasonic sensor distance threshold[cm]

const int photoresistorPin=28;  //Photoresistor pin to GP28
const int photoresistorThreshold = 750;  //Photoresistor threshold

const int buzzerPin = 5;  //buzzer pin to GP5

const int ledPin = 27;  //LED pin to GP27

const int alertRing = 550;  //alert ringing time [ms]
const int alertInterval = 75;  //alert interval time [ms]

void setup(){  //Autorun after start
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.println("Ultrasonic sensor:");
}

void loop(){  //Endless loop after start
  float distance = readSensorData();
  Serial.print(distance);
  Serial.println("cm ");
  if(distance <= distanceThreshold){
    photoresistor();
  }
  delay(5);
}

float readSensorData(){  //Ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distance = pulseIn(echoPin, HIGH)/58.00;  //Equivalent to (340m/s*1us)/2
  return distance;
}

void photoresistor(){  //Photoresistor
  int val=0;
  val=analogRead(photoresistorPin);
  Serial.print("Photoresistor:");
  Serial.print(val);
    if(val >= photoresistorThreshold){
    alert(ledPin);
    Serial.println(" detection! LED");
  } else {
    Serial.println(" detection! beep");
    alert(buzzerPin);
  }
}

void alert(int alertPin) {  //Alert by LED and buzzer
  digitalWrite(alertPin, HIGH);
  delay(alertRing);
  digitalWrite(alertPin, LOW);
  delay(alertInterval);
}


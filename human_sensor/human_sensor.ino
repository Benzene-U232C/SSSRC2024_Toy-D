const int echoPin = 16;  //US-015 Echo
const int trigPin = 17;  //US-015 Trig
const int distanceThreshold = 200;  //超音波センサーの距離閾値

const int photoresistorPin=28;  //フォトレジスタピン
const int photoresistorThreshold = 400;  //フォトレジスタ抵抗閾値

const int buzzerPin = 3;  //ブザーピン

const int ledPin = 15;  //LEDピン

void setup(){  //起動後自動実行
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.println("Ultrasonic sensor:");
}

void loop(){  //起動後無限ループ
  float distance = readSensorData();
  Serial.print(distance);
  Serial.print(" cm ");
  if(distance <= distanceThreshold){
    lad();
  }
  delay(200);
}

float readSensorData(){  //超音波センサー
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distance = pulseIn(echoPin, HIGH)/58.00;  //Equivalent to (340m/s*1us)/2
  return distance;
}

void lad(){  //フォトレジスタ
  int val=0;
  val=analogRead(photoresistorPin);
  Serial.print(val);
    if(val >= photoresistorThreshold){
    alert(ledPin);
    Serial.println(" LED");
  } else {
    Serial.println(" beep");
    alert(buzzerPin);
  }
}

/*
void beep() {  //ブザー
  int l = 0;
  for(l = 0; l <= 1; l++){
  digitalWrite(buzzerPin, HIGH);
  delay(150);
  digitalWrite(buzzerPin, LOW);
  delay(100);
  }
}

void light() {  //LED(ブザーと共通なので簡略化できそうな気はする)
  int i = 0;
  for(i = 0; i <= 1; i++){
  digitalWrite(ledPin, HIGH);
  delay(150);
  digitalWrite(ledPin, LOW);
  delay(100);
  }
}
*/

void alert(int alertPin) {  //LEDとブザーによる警告
  int i = 0;
  for(i = 0; i <= 1; i++){
  digitalWrite(alertPin, HIGH);
  delay(150);
  digitalWrite(alertPin, LOW);
  delay(100);
  }
}


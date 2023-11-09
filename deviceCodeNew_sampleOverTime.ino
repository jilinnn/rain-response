int rainSensor = A4;
int ledMOSFET = 3;
int motorMOSFET = 5;
int relayControl = 2;

void setup() {
  Serial.begin(9600);
  pinMode(rainSensor,INPUT);
  pinMode(ledMOSFET,OUTPUT);
  pinMode(motorMOSFET,OUTPUT);
  pinMode(relayControl,OUTPUT);
}

int countDrops(){
  int count = 0;
  int rainReading;
  float voltage;
  for (int ii = 0; ii < 10; ii++){
    rainReading = analogRead(rainSensor);
    voltage = rainReading/1024.0 * 5.0;
    if (voltage < 4.78) {
      count++;
    }
    delay(100);
  }
  return count;
}

// wipeSetting: OFF = 0; LOW = 1; HIGH = 2
void motorControl(int wipeSetting){
  switch (wipeSetting){
    case 0:
      analogWrite(motorMOSFET,0);
      break;
    case 1:
      analogWrite(motorMOSFET,190);
      digitalWrite(relayControl,LOW);
      delay(4500);
      digitalWrite(relayControl,HIGH);
      delay(4400);
      motorControl(0);
      break;
    case 2:
      analogWrite(motorMOSFET,255);
      digitalWrite(relayControl,LOW);
      delay(1500);
      digitalWrite(relayControl,HIGH);
      delay(1400);
      motorControl(0);
      break;
  }
}

void loop() {
  // OFF (0 drops per second)
  if (countDrops() == 0){
    analogWrite(ledMOSFET,0);
    motorControl(0);
  }
  // LOW intensity (< 5 drops per second)
  else if (countDrops() < 5){
    analogWrite(ledMOSFET,10);
    motorControl(1);
  }
  // HIGH intensity (>= 5 drops per second)
  else {
    analogWrite(ledMOSFET,50);
    motorControl(2);
  }
}
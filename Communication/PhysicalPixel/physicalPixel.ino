/*
 * 通过串口来控制 LED 的开关
 */
const int ledPin = 13;
int incomingByte;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  if(Serial.available()>0){
    incomingByte = Serial.read();
    if(incomingByte == 'l'){
      digitalWrite(ledPin, LOW);
      }

    if(incomingByte == 'h'){
      digitalWrite(ledPin, HIGH);
      }
    }

}

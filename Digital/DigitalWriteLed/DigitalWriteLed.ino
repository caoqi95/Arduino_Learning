/*
 * 流水灯：依次点亮每个LED然后依次熄灭
 */

 // 设置变量
 int ledPin;
 
void setup() {
  // 依次设置每个端口为输出模式
  for(ledPin=1;ledPin<7;ledPin++){
    pinMode(ledPin, OUTPUT);
    }
}

void loop() {
  // 依次点亮每个LED
  for(ledPin=1;ledPin<7;ledPin++){
    digitalWrite(ledPin, HIGH);
    delay(200);
    }
  // 依次熄灭每个LED
  for(ledPin=6;ledPin>0;ledPin--){
    digitalWrite(ledPin, LOW);
    delay(200);
    }
}

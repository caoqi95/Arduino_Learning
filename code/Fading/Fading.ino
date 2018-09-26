/*
 * 让 LED 实现渐变效果
 */

// 设置变量
int ledPin = 9;
int fadeValue;

void setup() {
  // setup() 中没有要设置的内容
}

void loop() {
  // 逐渐增加 LED 的亮度
  for(fadeValue = 0; fadeValue <= 255; fadeValue += 5){
    analogWrite(ledPin, fadeValue);
    delay(20);
    }
  // 逐渐减小 LED 的亮度
  for(fadeValue = 255; fadeValue >= 0; fadeValue -= 5){
    analogWrite(ledPin, fadeValue);
    delay(20);
    }
}

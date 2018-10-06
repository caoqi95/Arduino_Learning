/*
 * SwitchCase2:显示如何根据串行端口中收到的字符执行不同的操作。
 */
void setup() {
  // 初始化串行口
  Serial.begin(9600);

  // 初始化 LED 引脚
  for(int ledPin = 2; ledPin < 7; ledPin++){
    pinMode(ledPin, OUTPUT);
    }
}

void loop() {
  // 读取串行口内容
  if (Serial.available() > 0){
    int inByte = Serial.read();
    
    switch(inByte){
      case 'a':
        digitalWrite(2, HIGH);
        break; 
      case 'b':
        digitalWrite(3, HIGH);
        break;
      case 'c':
        digitalWrite(4, HIGH);
        break;
      case 'd':
        digitalWrite(5, HIGH);
        break;
      case 'e':
        digitalWrite(6, HIGH);
        break;
      default:
        // 熄灭所有的灯
        // 如果所有的 case 都没有匹配上，default 后面的代码就会被执行
        for(int ledPin = 2; ledPin < 7; ledPin++){
          digitalWrite(ledPin, LOW);
          }
        }
     }

}

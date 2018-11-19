/*
 * 通过蓝牙，实现手机语音控制 LED
 */
#include <SoftwareSerial.h>
#define YELLOW_PIN 13
#define RED_PIN 9


String voice;

void setup() {
  // 设置串行波特率
  Serial.begin(9600);
  // 将 led 引脚设为输出模式
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

// 获取指令函数。将串口传输的字符连接成完整的字符串指令
String getVoice(){
  while(Serial.available()){
    delay(50);
    char orderChar = Serial.read();
    // 如果按下“#”号键的话，停止获取语音
    if(orderChar == "#")
      break;
      voice += orderChar;
    }
   return voice;
  }
// 使 LED 闪烁
void blink(){
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(RED_PIN, HIGH);
  delay(100);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(RED_PIN, LOW); 
  delay(100);
  }
// 控制函数。解析字符串指令并执行相应动作
void control(String voice){
  // 打开黄色 LED 
  if(voice.endsWith("yellow")){
    digitalWrite(YELLOW_PIN, HIGH);
    //Serial.println("Light ON");
    }
   // 打开绿色 LED
  if(voice.endsWith("red")){
    digitalWrite(RED_PIN, HIGH);
    //Serial.println("Light ON");
    }  
  // 闪烁
  if(voice.endsWith("blink")){
    blink();
    }
  // 停止闪烁
  if(voice.endsWith("stop")){
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(RED_PIN, HIGH);}
  // 关闭 LED
  if(voice.endsWith("off")){
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(RED_PIN, LOW);
    }
  }

void loop() {
  String voice = getVoice();
  control(voice);
  voice = ""; // 将 voice 清空
}

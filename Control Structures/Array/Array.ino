/*
 * Array: 使用数组结构来实现循环亮灭灯，通过这个小项目学会如何使用数组结构
 */

// 定义时间
int timer = 100;
// 定义数组
int ledPins[] = {2,7,4,6,5,3}
// led 总数
int pinCount = 6；

void setup() {
  // 依次将引脚设置为输出模式
  for(int thisPin=0; thisPin < pinCount; thisPin++){
    pinMode(ledPins[thisPin], OUTPUT);
    }
}

void loop() {
  // 从底引脚到高引脚
  for(int thisPin=0; thisPin < pinCount; thisPin++){
    // 点亮
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    // 熄灭
    digitalWrite(ledPins[thisPin], LOW);
    }

  // 从高引脚到底引脚
  for(int thisPIn = pinCount - 1; thisPin > 0; thisPin--){
    // 点亮
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    // 熄灭
    digitalWrite(ledPins[thisPin], LOW);
    }
}

/*
 * Timer：使用 TimerOne 定时器库来制作数字时钟
 */
 
#include "TimerOne.h"
#include "SevSeg.h"

SevSeg sevseg;

// 申明变量
int minutes = 0;
int seconds = 0;

void setup() {
  // 设置数码管
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 12, 13};
  byte segmentPins[] = {7, 6, 5, 10, 11, 8, 9, 4};
  byte hardwareConfig = COMMON_CATHODE;

  // 初始化数码管
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins);

  // 初始化定时器为 1s
  Timer1.initialize(1000000);
  // 设置中断函数
  Timer1.attachInterrupt(timeIsr);
 
}

//  定时器中断处理函数
void timeIsr(){
  seconds++;
  if(seconds > 59){
    seconds = 0;
    minutes++;
    if(minutes > 59){
      minutes = 0;
      }
    }
  }
  
void loop() {
  // 设置数码管的显示
  sevseg.setNumber(minutes * 100 + seconds, -1);
  // 重复刷新数码管的显示
  sevseg.refreshDisplay();

}

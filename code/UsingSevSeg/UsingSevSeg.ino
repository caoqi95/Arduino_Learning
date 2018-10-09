/*
 * SevSeg：使用 SevSeg 数码管库和光敏电阻来驱动一个数码管显示数字
 */

#include "SevSeg.h"

// 实例化 7 段对象
SevSeg sevseg;

// 设置数码管位数
byte numDigits = 1;
// 定义数码管共极连接的引脚
byte digitPins[] = {3, 2, 2, 2};
// 数码管各段对应的引脚
byte segmentPins[] = {7, 6, 5, 10, 11, 8, 9, 4};
// 设定为共阳极数码管
byte hardwareConfig = COMMON_ANODE;

// 申明变量
int readValue = 0;
int showValue = 0; 

void setup() {
  // 初始化数码管
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins);
  /* 调试光敏电阻范围用
  // 初始化串行口
  Serial.begin(9600);
  */
}

void loop() {
  // 读取光敏电阻的值
  readValue = analogRead(A0);
  /* 打印光敏电阻的值
  Serial.println(readValue);
  */
  // 将光敏电阻的值，映射到 0-9 的范围 （我用手机打灯照光敏电阻，光敏电阻范围大概在 450-900 之间）
  showValue = map(readValue, 450, 900, 0, 9);
  // 显示数码管
  sevseg.setNumber(showValue, -1);
  // 必须重复运行刷新数码管的显示
  sevseg.refreshDisplay();
}

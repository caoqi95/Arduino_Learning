/*
 * 驱动四位数码管
 */
#include "SevSeg.h"

SevSeg sevseg;

// 申明变量
int numToShow = 0;
int delaycount = 0;

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 12, 13};
  byte segmentPins[] = {7, 6, 5, 10, 11, 8, 9, 4};
  byte hardwareConfig = COMMON_CATHODE;

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins);

}

void loop() {
  // 通过变量自加来达到延时效果，如果使用 delay 的话则会打断数码管的显示
  delaycount++;
  if(delaycount == 5000){
    delaycount = 0;
    numToShow++;
    }

   if(numToShow > 9999){
    numToShow = 0;
    }

    sevseg.setNumber(numToShow, -1);
    sevseg.refreshDisplay();
}

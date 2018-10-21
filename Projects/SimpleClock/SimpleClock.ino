/*
 * 搭建简易的电子时钟
 */
#include <virtuabotixRTC.h> // 驱动 RTC 模块需要的库
#include <LiquidCrystal_I2C.h> 


LiquidCrystal_I2C lcd(0x27,16,2);

//引脚连线： CLK -> 4 , DAT -> 3, Reset -> 2
virtuabotixRTC RTC(4, 3, 2);

void setup() {
 Serial.begin(9600);
 lcd.init(); // 初始化 LCD
 lcd.backlight(); // 打开背光
 lcd.home ();
 // 设定时间，分别：秒，分，时，星期，日，月，年
 //RTC.setDS1302Time(30, 48, 17, 3, 17, 10, 2018);
 //初次烧录时，需执行这行代码，之后需要注释掉 
}

void loop() {
 lcd.clear(); // 清除屏幕后，从 RTC 模块中获取时间，然后打印到 LCD 上
 RTC.updateTime();
 lcd.setCursor(0,0);
 lcd.print(RTC.dayofmonth);
 lcd.print("/");
 lcd.print(RTC.month);
 lcd.print("/");
 lcd.print(RTC.year);
 lcd.setCursor(0,1);
 lcd.print(RTC.hours);
 lcd.print(":");
 lcd.print(RTC.minutes);
 lcd.print(":");
 lcd.print(RTC.seconds);
 delay(1000);
}

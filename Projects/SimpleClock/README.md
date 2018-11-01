这周主要学习 DS1302 时钟模块的使用，并用其搭建一个简易的电子时钟，此篇文章主要参照参考文章<sup>[2]</sup>。

## 硬件准备

+ Arduino UNO 一个
+ DS1302 时钟模块一枚
+ 1602LCD一块(附带 PCF8574T 转接板)
+ 面包板一块
+ 连接线若干

## 软件准备

+ Arduino IDE
+ [[RTC Virtuabotix Library](https://drive.google.com/file/d/1GDuLWUANun5toL-XsEaFfaw2tv0mvhjB/view?usp=sharing)
](https://drive.google.com/file/d/1GDuLWUANun5toL-XsEaFfaw2tv0mvhjB/view)
+ [LCD i2c Library](https://drive.google.com/file/d/1Oc56q2GPs5SOA-PdbVHHSxKCnI9KY5xd/view)


## 电路连接

+ DS1302 的连线：VCC ——> 5V，GND ——> GND，CLK ——> 4，DAT ——> 3，RST ——> 2
+ LCD 的连线：VCC ——> 5V，GND ——> GND，SDA ——> A4，SCL ——> A5

![](https://upload-images.jianshu.io/upload_images/2759738-003a4afa76fb14d2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


## 实现代码

[Arduino_Learning/SimpleClock](https://github.com/caoqi95/Arduino_Learning/blob/master/Projects/SimpleClock/SimpleClock.ino)

```
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
 RTC.setDS1302Time(30, 28, 17, 3, 17, 10, 2018); 
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
```

## 烧录代码

代码编译完没问题后，点击图中所选按钮将其上传至 Arduino UNO 板上。烧录没问题后，就可以在 LCD 上观察到结果了。

![](https://upload-images.jianshu.io/upload_images/2759738-ce5fa1128d37d263.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


## 实际结果


![](https://upload-images.jianshu.io/upload_images/2759738-794988de39caecf3.gif?imageMogr2/auto-orient/strip)


## 心得总结 

对于驱动 DS1302 时钟模块的库有好多种，但大多数方法是差不多的。这个简易的时钟虽然可以根据设定的时间来显示实时的时间，但是需要注意：初次运行的时候需要设置好时间，之后需要把设定时间的那行代码注释掉。因为时钟模块自带电池，在 Arduino 板子掉电后，还是能继续计时的，所以插上电后还是实时的时间。如果在校准时间之后，还是不能正确的显示时间的话，可以在 DS1302 时钟模块的引脚增加一个电阻。下次按照参考文章<sup>[1]</sup>的方法试试外部中断的方法来校准时间。

## 参考文章

[1]. [第20课 DS1302时钟模块与外部定时器](http://ardui.co/archives/583)

[2]. [How to simply use DS1302 RTC module with Arduino board and LCD screen](https://surtrtech.com/2018/01/27/how-to-simply-use-ds1302-rtc-module-with-arduino-board-and-lcd-screen/)



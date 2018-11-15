这周主要学习的是蜂鸣器和超声波传感器的使用，超声波传感器在智能小车上会有很多的用处。后来结合了 LCD 的使用，搭建了简易的距离检测警报器。


## 硬件准备

+ Arduino UNO 一个
+ 蜂鸣器一枚
+ 1602LCD一块(附带 PCF8574T 转接板)
+ 超声波传感器一个
+ 面包板一块
+ 连接线若干

## 软件准备

+ Arduino IDE
+ [Ultrasonic Library](https://github.com/JRodrigoTech/Ultrasonic-HC-SR04)
+ [LCD i2c Library](https://drive.google.com/file/d/1Oc56q2GPs5SOA-PdbVHHSxKCnI9KY5xd/view)


## 电路连接

+ 超声波传感器的连线：VCC ——> 5V，GND ——> GND，Trig ——> A0，Echo ——> A1
+ LCD 的连线：VCC ——> 5V，GND ——> GND，SDA ——> A4，SCL ——> A5
+ 蜂鸣器的连线：长脚 ——> 7，短脚——> GND

![](https://upload-images.jianshu.io/upload_images/2759738-18db983d6a607887.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



## 实现代码

[Arduino_Learning/MeasuringDistance](https://github.com/caoqi95/Arduino_Learning/blob/master/Projects/MeasuringDistance/MeasuringDistance.ino)
```
/*
 * 使用超声波传感器测量距离并显示在 LCD 上，当距离小于 20 时，发出警报
 */

// 导入库文件
#include "Ultrasonic.h"
#include <LiquidCrystal_I2C.h> 
#include "Wire.h"

LiquidCrystal_I2C lcd(0x27,16,2);

//设置(trig,echo)的连线
Ultrasonic ultrasonic(A0,A1);

// 设置变量
int distance;

// 设置引脚
int BuzzerPin = 7;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(BuzzerPin, OUTPUT);
}

void loop()
{
  distance = ultrasonic.Ranging(CM); // 使用'CM'表示厘米或者 'INC' 表示英寸
  // 打印距离
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print("cm");
  digitalWrite(BuzzerPin, LOW);
  
  // 如果测量的距离小于 20 就发出警报
  if (distance < 20 ){
      lcd.setCursor(0,0);
      lcd.print("Danger! Danger!");
      lcd.setCursor(0,1);
      lcd.print("Distance: ");
      lcd.print(distance);
      lcd.print("cm");
    digitalWrite(BuzzerPin, HIGH);
  }
   // 延时 1s 
  delay(1000);
}
```

再附赠一个警报加亮灯的版本：

```
/*
 * 使用超声波传感器测量距离并显示在 LCD 上，当距离小于 20 时，发出警报同时亮灯提示
 */

// 导入库文件
#include "Ultrasonic.h"
#include <LiquidCrystal_I2C.h> 
#include "Wire.h"

LiquidCrystal_I2C lcd(0x27,16,2);

//设置(trig,echo)的连线
Ultrasonic ultrasonic(A0,A1);

// 设置变量
int distance;

// 设置引脚
int BuzzerPin = 7;
int ledPin = 8;


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(BuzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  distance = ultrasonic.Ranging(CM); // 使用'CM'表示厘米或者 'INC' 表示英寸
  // 打印距离
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print("cm");
  digitalWrite(BuzzerPin, LOW);
  digitalWrite(ledPin, LOW);
  // 如果测量的距离小于 20 就发出警报
  if (distance < 20 ){
      lcd.setCursor(0,0);
      lcd.print("Danger! Danger!");
      lcd.setCursor(0,1);
      lcd.print("Distance: ");
      lcd.print(distance);
      lcd.print("cm");
      digitalWrite(BuzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
  }
   // 延时 1s
  delay(1000);
}
```

## 烧录代码

代码编译完没问题后，点击图中所选按钮将其上传至 Arduino UNO 板上。烧录没问题后，就可以在 LCD 上观察到结果了。

![](https://upload-images.jianshu.io/upload_images/2759738-084cf4c5ec802be7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



## 实际结果

+ 距离大于 20 cm 的情况：

![](https://upload-images.jianshu.io/upload_images/2759738-7a31766fdfb9f645.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

+ 距离小于 20 cm 的情况：
（同时蜂鸣器会发出警报声。 LED 版本的话，LED 同时也会亮起）

![](https://upload-images.jianshu.io/upload_images/2759738-0ec1a5ee77868761.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)




## 心得总结 

刚开始看参考文章<sup>[1]</sup>的时候，试着运行了代码，但结果一直显示 0 cm。将 5v 切换到 3.3v ，情况会有所改变，但是一段时间后又显示 0 cm。这个问题一直没解决。最后试着连接电路，将 5v 的接口接到面包板上（因为 5v 端口不够用），LCD 和 超声波传感器再分别连接 5v。烧录代码后可以正常测量距离了，虽然有时候还是不准确。

这周的项目还是简单级别的，一直想尝试难一点的项目，奈何没有很好的点子以及很多器材缺失。希望下周能够尝试更难一点的项目。

## 参考文章

[1]. [How to use the HC-SR04 Ultrasonic Sensor](http://www.ardumotive.com/how-to-use-the-hc-sr04-ultrasonic-sensor-en.html#)




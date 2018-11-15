教授说每个周三学习一下 Arduino ，然后就每个周三只学习这个。摸鱼了这么久，应该动手搞一搞简单的小项目，要不然这周的会议上，没什么东西可说的。

## 硬件准备

+ Arduino UNO 一个
+ 温湿度传感器一枚
+ PCF8574T 转接板一个
+ 1602LCD一块
+ 面包板一块
+ 连接线若干

## 软件准备

+ Arduino IDE

## 电路连接

本项目直接使用 PCF8574T 转接板来驱动 1602 LCD 显示屏，这样会节省很多 Arduino 的 IO 口，也省去了很多接线的麻烦。PCF8574T 转接板 包含四个接口：VCC，GND，SDA 和 SCL。分别进行这样的连接：VCC -- 5V，GND -- GND，SDA -- A4，SCL -- A5。
温湿度传感器包含 3 个引脚，从有网面的一面看，从左到右分别为 DATA，VCC，GND。对其进行这样的连接：DATA -- A0，VCC -- 3.3V，GND -- GND。
![](https://upload-images.jianshu.io/upload_images/2759738-0f63673543cf5dcd.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 实现代码

[Arduino_Learning/Projects/DetectHT](https://github.com/caoqi95/Arduino_Learning/blob/master/Projects/DetectHT/DetectHT.ino)

```

/*
 * 使用温湿度传感器检测信息并显示在 LCD 上
 */
#include "Wire.h" // 导入驱动 LCD 需要的库
#include "LiquidCrystal_I2C.h"
#include "dht.h" // 导入 dht 库，用于温湿度传感器
#define dht_pin A0 // 将温湿度传感器的数据端口接至 A0 

dht DHT;

// 设置 LCD 
LiquidCrystal_I2C lcd(0x27,16,2); 

void setup() {
  // 延时等待系统初始化
  delay(1000);
  // 初始化 LCD 
  lcd.init();
  // 打开屏幕背光
  lcd.backlight();
  // LCD 屏显示 Humidity(%):
  lcd.print("Humi(%): ");
  // LCD 屏显示 Temp(C): 
  lcd.setCursor(0, 1);  
  lcd.print("Temp(C): ");
}

void loop() {
  // 读取温湿度传感器的数据
  DHT.read11(dht_pin);
  // LCD 显示 采集的温湿度数据
  lcd.setCursor(8,0);
  lcd.print(DHT.humidity,1); 
  lcd.setCursor(8,1);
  lcd.print(DHT.temperature,1);
  delay(1000);
}
```

## 烧录代码

代码编译完没问题后，点击图中所选按钮将其上传至 Arduino UNO 板上。烧录没问题后，就可以在 LCD 上观察到结果了。

![](https://upload-images.jianshu.io/upload_images/2759738-8707bac9b5377f74.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 实际结果

如果湿度没有变化的话，可以试着对传感器哈一口气，就能观察到数值的变换了。

![](https://upload-images.jianshu.io/upload_images/2759738-b769efab1dbb6c9a.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 心得总结 

做完这个小项目，才发现并不是那么难，寥寥几行代码就完成了。增加了一点点信心，希望之后能够做出一些有创意又有意思的东西来。

## 参考文章
[1]. [How to use the DHT11 Temperature – Humidity Sensor with Arduino](https://www.brainy-bits.com/dht11-tutorial/)

[2]. [USING PCF8574 BACKPACKS WITH LCDS AND ARDUINO](https://www.instructables.com/id/Using-PCF8574-backpacks-with-LCD-modules-and-Ardui/)

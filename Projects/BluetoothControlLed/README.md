上周鼓捣 Deepin 系统去了，就没认真学习，发文章。这周学习的是蓝牙模块的使用。实现蓝牙模块控制 LED 的开关。蓝牙模块的用处很多，主要用于数据的传输，可以通过其和传感器的联合使用，收集一些需要的数据并传到电脑上进行处理。

## 设置蓝牙
本人使用的蓝牙模块是 HC-05，由实验室的小伙伴友情提供。因为是他人使用过的，所以得进行初始化设置。
+ 进入 AT 模式：具体参考这篇文章：[Arduino使用HC05蓝牙模块与手机连接](https://www.jianshu.com/p/4ebf1a01df51)
+ AT 模式的一些命令：
进入 AT 模式后，重新设置名称和密码，并将蓝牙设置为从模式，因为这个项目中，手机是主机。
```
AT+ORGL    # 恢复出厂模式
AT+NAME=Bluetooth    # 设置蓝牙名称为 Bluetooth
AT+ROLE=0    # 设置蓝牙为从模式
AT+CMODE=1    # 设置蓝牙为任意设备连接模式
AT+PSWD=1234    # 设置蓝牙匹配密码为1234
```

## 硬件准备
+ Arduino UNO 一个
+ 蓝牙模块 HC-05 一个
+ Android 手机
+ LED 一个
+ LCD 一块
+ 面包板一块
+ 连接线若干

## 软件准备

+ Arduino IDE
+ 在 Google APP Store 或者其他安卓市场下载 Arduino Bluetooth controler app


## 电路连接
LCD 的连线：VCC ——> 5V，GND ——> GND，SDA ——> A4，SCL ——> A5
LED 的连线：长脚 ——>先接个电阻，再连接 13，短脚 ——> GND
蓝牙的连线：VCC ——> 5V，GND ——> GND，RXD ——> TXD，TXD ——> RXD，这里需要注意蓝牙的 RXD 要与 Arduino 的 TXD 连接，TXD 要与 Arduino 的 RXD 连接，**两者是交错连接的**。**同时在烧录的时候，注意断开 TXD 和 RXD 的连接**，要不然烧录的时候会受到干扰，继而会报错。
![](https://upload-images.jianshu.io/upload_images/2759738-23df4966edd2b873.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 实现代码
```
/*
 * 通过蓝牙用手机控制 LED,并在 LCD 上显示开关信息
 */
#include <LiquidCrystal_I2C.h>
#include <wire.h>

// 设置 LCD 
LiquidCrystal_I2C lcd(0x27, 16, 2);
// 设置 LED 引脚

int led = 13;
void setup() {
  pinMode(led, OUTPUT);
  // 将波特率设置为 9600
  Serial.begin(9600);
  // LCD 初始化
  lcd.init();
  // 打开屏幕背光
  lcd.backlight();
}

void loop() {
  if(Serial.available()>0){
    char c = Serial.read();
    if(c=='1'){
      digitalWrite(led, HIGH);
      lcd.setCursor(5,0);
      lcd.print("LED ON ");
      }
    if(c=='0'){
      digitalWrite(led, LOW);
      lcd.setCursor(5,0);
      lcd.print("LED OFF");
      }
     }
}
```

## 烧录代码
代码编译完没问题后，点击图中所选按钮将其上传至 Arduino UNO 板上。
![](https://upload-images.jianshu.io/upload_images/2759738-222cf4f13c28c498.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 手机设置
1. 手机搜索蓝牙，输入密码并连接。
![](https://upload-images.jianshu.io/upload_images/2759738-18ca058b9cee4707.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

2. 之后选择 `Switch mode`。
![](https://upload-images.jianshu.io/upload_images/2759738-430eef21e076c1d8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
3. 对按键进行设置。
![](https://upload-images.jianshu.io/upload_images/2759738-75f1e792fa96c67f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
4. 点击 APP 上的开关，就能够实现控制 LED 了。
![](https://upload-images.jianshu.io/upload_images/2759738-6d9e6bdc53c1b5e4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 实际结果
LED 打开：
![](https://upload-images.jianshu.io/upload_images/2759738-f25b5abc4d1726dd.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
LED 关闭：
![](https://upload-images.jianshu.io/upload_images/2759738-06db07acb029ccc2.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
## 心得总结 
昨天晚上鼓捣了很久，都没有出现正确的结果，后来才发现，控制 LED 开关的时候波特率设置成了 38400，应该设置成 9600。而 38400 这个波特率是进入 AT 模式的波特率。这个也是一个需要注意的点。还有一个需要注意的就是烧录的时候一定要断开 TXD 和 RXD 的连接，要不然烧录会受到干扰，这个问题也困扰了我很久。

## 参考文章
[1]. [Arduino使用HC05蓝牙模块与手机连接](https://www.jianshu.com/p/4ebf1a01df51)

[2]. [Arduino and HC-05 Bluetooth Module Tutorial](https://howtomechatronics.com/tutorials/arduino/arduino-and-hc-05-bluetooth-module-tutorial/)

[3]. [Arduino蓝牙模块HC-06错误](https://stackoverrun.com/cn/q/9636941)




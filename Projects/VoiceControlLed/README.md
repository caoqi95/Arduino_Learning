为了加快 Arduino 的学习，决定周一这一天的上午也用来学习 Arduino。今天还是继续学习蓝牙模块的使用。实现通过蓝牙模块，在手机端语音控制 LED 的功能。这种思路后续再扩宽的话，加上动手能力强的话，完全自己搭建智能家居系统。

本文章主要参考的是这篇：[Android 通过蓝牙语音控制 Arduino](https://www.jianshu.com/p/981266b507f5)，非常感谢作者的教程！

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
+ 红色和黄色 LED 各一个
+ Android 手机（**有谷歌套件**）
+ 面包板一块
+ 连接线若干

## 软件准备

+ Arduino IDE
+ 在 Google APP Store 或者其他安卓市场下载 Arduino Voice Control


## 电路连接

黄色 LED 的连线：长脚 ——>先接个电阻，再连接 13，短脚 ——> GND
红色 LED 的连线：长脚 ——>先接个电阻，再连接 12，短脚 ——> GND
蓝牙的连线：VCC ——> 5V，GND ——> GND，RXD ——> TXD，TXD ——> RXD，这里需要注意蓝牙的 RXD 要与 Arduino 的 TXD 连接，TXD 要与 Arduino 的 RXD 连接，**两者是交错连接的**。**同时在烧录的时候，注意断开 TXD 和 RXD 的连接**，要不然烧录的时候会受到干扰，继而会报错。

![](https://upload-images.jianshu.io/upload_images/2759738-6ecd1227154726c9.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


## 实现代码
```
/*
 * 通过蓝牙，实现手机语音控制 LED
 */
#define YELLOW_PIN 13
#define RED_PIN 12


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
   // 打开红色 LED
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
```

## 烧录代码
代码编译完没问题后，点击图中所选按钮将其上传至 Arduino UNO 板上。

![](https://upload-images.jianshu.io/upload_images/2759738-5e18cd448c27ea30.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 手机设置
1. 点击 `CONNECT`，选择蓝牙，点击连接。
![](https://upload-images.jianshu.io/upload_images/2759738-d898f3850e4a44bd.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

2. 点击中间的麦克风，进行语音输入


## 实际结果

+ 语音输入 `turn on the yellow`：黄色的灯会打开
+ 语音输入 `turn on the red`：红色的灯会打开
+ 语音输入 `blink`：两个灯会一起闪烁
+ 语音输入 `stop`：两个灯会停止闪烁，并保持常亮
+ 语音输入 `turn off`：两个灯都会熄灭

这个项目的结果最好的显示方式是录视频，但我一个人忙不过来，就放弃了。结果可以参考上面那篇文章的结果。我主要增加了按颜色实现语音控制 LED ，以及 LED 闪烁功能的开启和关闭这些功能。只是代码方面的修改，及语音方面输入的不同。

## 心得总结 
刚开始在看到一篇用 BitVoice 这个工具实现语音控制的文章，但下载了 BitVoice 这个软件后，没有搞懂怎么使用，就放弃了。后来在收藏夹里又突然发现上面这篇文章，就赶紧参考写代码实现了。在实现的过程中，感觉英文发音比较准的话，会比较容易控制；发音不好的话，就会识别不清，得多次输入。

## 参考文章
[1]. [Android 通过蓝牙语音控制 Arduino](https://www.jianshu.com/p/981266b507f5)

[2]. [Arduino使用HC05蓝牙模块与手机连接](https://www.jianshu.com/p/4ebf1a01df51)





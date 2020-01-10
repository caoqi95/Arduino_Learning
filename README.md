# Arduino_Learning
有些是练习过官网 Tutorial 里 Bulit-in Examples 中的简单例子后，按照自己的理解及思路编写的代码；有些是自己找的例子，然后自己实现的代码。并没有完整覆盖官网的全部示例，因为缺少一些元器件。


### Digital

+ StateChangeDetection：识别按键按下的状态，并计算按下的次数。
+ DigitalWriteLed：流水灯，依次点亮每个 LED 然后依次熄灭。


### Analog

+ Calibration: 定义期望的模拟传感器值的最大值和最小值。
+ Fading: 使用模拟输出（PWM 引脚）淡化 LED。


### Communication

+ PhysicalPixel: 通过向 Arduino 发送数据来打开和关闭 LED。
+ ReadASCIIString: 将串行口读取的数据解析出来给 RGB LED 进行调光。

### Control Structures
+ Arrays: For 循环示例的变体，演示如何使用数组。
+ SwitchCase: 如何在离散数量的值之间进行选择。
+ SwitchCase2: 显示如何根据串行端口中收到的字符执行不同的操作。


### Digtial Tube
+ SingleDigitalTube: 驱动带共阳极的数码管，显示数字 0~9。
+ RandomDice: 随机生成一个数字。
+ UsingSevSeg: 使用 SevSeg 库和光敏电阻来驱动数码管。
+ FourDigits：驱动四个数码管来显示数字。
+ Timer：使用 TimerOne 库来制作一个时钟。

### Display
+ 1602LCD:  使用 1602 LCD 来显示 "Hello, World!" 以及运行时间。

### Sensors
+ DHC：使用温湿度传感器来检测温湿度。

### Projects
+ DetectHT：检测温湿度并将其显示在 LCD 上。
+ SimpleClock：使用 RTC 模块来制作一个简单的时钟。
+ MeatureDistance：使用超声波传感器来检测距离，并将距离显示在 LCD 上。当距离小于 20 cm 时发出警报。
+ MeatureDistance2.0：使用超声波传感器来检测距离，并将距离显示在 LCD 上。当距离小于 20 cm 时发出警报并亮灯提醒。
+ heartShow：使用 8x8 矩阵 LED 屏来实现 “心动” 的效果。
+ BluetoothControlLed：通过蓝牙连接 Android 手机和 Arduino， 然后用手机控制 LED 的开关。
+ VoiceControlLed：通过蓝牙连接 Android 手机和 Arduino， 然后用语音控制 LED 的开关。

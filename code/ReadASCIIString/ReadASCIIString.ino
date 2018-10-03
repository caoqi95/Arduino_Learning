/*
 * Read ASCII String：将串行口读取的数据解析出来给RGB LED 进行调光
 * 使用的是共阴极 RGB LED，共阴极接 GND
 */

 // 定义 LED 引脚
 const int redPin = 6;
 const int greenPin = 5;
 const int bluePin = 3;
 
 void setup() {
  // 设置串口通信的波特率
  Serial.begin(9600);

  // 将 LED 的三个引脚设置为输出模式
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  }

void loop() {
   
  while (Serial.available() > 0){  // 判断串口是否有数据
    
    // 声明一些用于存储串行信息的局部变量，用于表示 LED 的亮度。
    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();

    // 检查读入的数据是否有换行符，有换行符表示读取完毕
    if (Serial.read() == '\n'){

      // 将 RGB 的值约束到 0-255 之间约束并且进行数学运算
      // 如果是共阳极写成：color = color - constrain(color, 0, 255)
      red = constrain(red, 0, 255);
      green = constrain(green, 0, 255);
      blue = constrain(blue, 0, 255);

      // 改变 LED 的颜色
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);

      // 将每个 LED 的值转换成十六进制的值发送回串行监视器
      Serial.println(red, HEX);
      Serial.println(green, HEX);
      Serial.println(blue, HEX);
      }  
    }
}

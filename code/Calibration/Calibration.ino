/*
 * 校准传感器
 */

// 设置常量
const int sensorPin = A0; // 传感器的引脚设置为A0
const int ledPin = 3; // LED的引脚设置为3

// 设置变量
int sensorValue = 0; // 传感器的值
int sensorMin = 1023; // 最小的传感器的值
int sensorMax = 0; // 最大的传感器的值


void setup() {
  // 打开LED指示校准周期的开始：
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // 在最开始的5秒内校准
  while(millis() < 5000){
    sensorValue = analogRead(sensorPin);
    
    // 记录传感器最大的值
    if(sensorValue > sensorMax){
      sensorMax = sensorValue;
      }

    // 记录传感器最小的值
    if(sensorValue < sensorMin){
      sensorMin = sensorValue;
      }
    }

   // 发出校准周期结束的信号
   digitalWrite(13, LOW);
}

void loop() {
  // 读取传感器
  sensorValue = analogRead(sensorPin);

  // 将校准应用于传感器读数
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // 如果传感器值超出校准期间读取的范围：
  sensorValue = constrain(sensorValue, 0, 255);

  // 使用校准值淡化LED：
  analogWrite(ledPin, sensorValue);
}

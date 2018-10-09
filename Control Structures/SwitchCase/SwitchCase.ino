/*
 * SwithCase
 */
const int sensorMin = 0;
const int sensorMax = 600;

void setup() {
  // 初始化串行口
  Serial.begin(9600);
}

void loop() {
  // 读取传感器
  int sensorReading = analogRead(A0);
  // 将传感器的范围映射为 0-3 这 4 个选项
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  // 根据不同的范围打印不同的结果
  switch(range){
    case 0:
      Serial.println("dark");
      break;
    case 1:
      Serial.println("dim");
      break;
    case 2:
      Serial.println("medium");
      break;
    case 3:
      Serial.println("bright");
      break;
      }
   delay(1);

}

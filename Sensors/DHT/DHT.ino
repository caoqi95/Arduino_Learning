/*
 * 温湿度传感器的使用
 */

#include <dht.h>

// 将 DHT 的数据端口连接至 A0 口
#define dht_apin A0 

dht DHT;
 
void setup(){ 
  Serial.begin(9600);
  // 延时，让系统启动
  delay(500);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  // 延时，等待连接
  delay(1000);
 
}
 
void loop(){
    // 读取传感器数据
    DHT.read11(dht_apin);
    // 打印湿度
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    // 打印温度
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(5000);
 
  //Fastest should be once every two seconds.
 
}

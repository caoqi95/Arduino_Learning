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

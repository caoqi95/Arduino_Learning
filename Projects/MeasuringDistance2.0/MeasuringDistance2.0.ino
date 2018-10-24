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

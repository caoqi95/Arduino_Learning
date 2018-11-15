
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

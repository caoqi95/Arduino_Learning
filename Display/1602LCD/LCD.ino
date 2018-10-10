#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// set the LCD address to 0x27 for a 16 chars and 2 line display
// 为一个16字符和2行显示，设置 LCD 的地址为 0x27 (请注意自己的地址，可能会不一样)
LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{
   // 初始化 LCD
   lcd.init(); 
   // 打开背光
   lcd.backlight(); 
   // 打印内容
   lcd.print("Hello, Wrold!"); 

}
void loop()
{
    // 另起一行
   lcd.setCursor(0,1);
   // 打印时间
   lcd.print(millis()/1000);
}

/*
 * 查询 LCD 总线 I2C 的地址
#include <Wire.h>
 
void setup(){
  Wire.begin();
  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
}
void loop(){
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for (address = 1; address < 127; address++ ){
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0){
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    }else if (error == 4){
      Serial.print("Unknow error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
  delay(5000); // wait 5 seconds for next scan
}
 */

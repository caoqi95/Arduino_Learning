/*
 * State change detection
 */

// 定义端口
const int ledPin = 13;
const int buttonPin = 2;

// 设置变量
int currentButtonState = 0;
int lastButtonState = 0;
int count = 0;

void setup() {
  // 初始化端口
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  // 设定串行通信的波特率
  Serial.begin(9600);
}

void loop() {
  // 读取按键端口数据
  currentButtonState = digitalRead(buttonPin);

  
  if (currentButtonState != lastButtonState){  // 检测按键状态是否与上一状态一样
    if (currentButtonState == HIGH){           // 若不一样，则判断当前按键状态是否为按下
      digitalWrite(ledPin, HIGH);
      count++;
      Serial.println("on");
      Serial.println("the Count of Puches: ");
      Serial.println(count);
      }
      else{
        digitalWrite(ledPin, LOW);
        Serial.println("off");
        }
    delay(100);
    }
  lastButtonState = currentButtonState;

}

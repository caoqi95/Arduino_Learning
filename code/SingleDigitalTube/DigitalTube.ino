/*
 * 驱动一个共阳极的数码管,显示数字 0~9 
 */

// 设定控制各段的数字引脚
int pin_a = 7;
int pin_b = 6;
int pin_c = 5;
int pin_d = 10;
int pin_e = 11;
int pin_f = 8;
int pin_g = 9;
int pin_p = 4;

// 根据共阳极/共阴极数码管段码表，定义 0~9 显示的各段开关状态
int numTable[10][8]={
  // 共阳极数码管段码，将共极接 Vcc(5v/3.3v)
  // 0 为点亮，1 为关闭
  // a  b  c  d  e  f  g  dp
  {0, 0, 0, 0, 0, 0, 1, 1},     // 0
  {1, 0, 0, 1, 1, 1, 1, 1},     // 1
  {0, 0, 1, 0, 0, 1, 0, 1},     // 2
  {0, 0, 0, 0, 1, 1, 0, 1},     // 3
  {1, 0, 0, 1, 1, 0, 0, 1},     // 4
  {0, 1, 0, 0, 1, 0, 0, 1},     // 5
  {0, 1, 0, 0, 0, 0, 0, 1},     // 6
  {0, 0, 0, 1, 1, 1, 1, 1},     // 7
  {0, 0, 0, 0, 0, 0, 0, 1},     // 8
  {0, 0, 0, 0, 1, 0, 0, 1},     // 9

  
  // 共阴极数码管段码,将共极接 GND 
  // 1 为点亮，0 为关闭
  // a  b  c  d  e  f  g  dp
  //{1, 1, 1, 1, 1, 1, 0, 0},     // 0
  //{0, 1, 1, 0, 0, 0, 0, 0},     // 1
  //{1, 1, 0, 1, 1, 0, 1, 0},     // 2
  //{1, 1, 1, 1, 0, 0, 1, 0},     // 3
  //{0, 1, 1, 0, 0, 1, 1, 0},     // 4
  //{1, 0, 1, 1, 0, 1, 1, 0},     // 5
  //{1, 0, 1, 1, 1, 1, 1, 0},     // 6
  //{1, 1, 1, 0, 0, 0, 0, 0},     // 7
  //{1, 1, 1, 1, 1, 1, 1, 0},     // 8
  //{1, 1, 1, 1, 0, 1, 1, 0},     // 9
};

  
void setup() {
  // 设置 4~11 引脚为输出模式
  for (int i=4; i<=11; i++){
    pinMode(i, OUTPUT);
    }
}

void loop() {
  // 依次显示 0~9 
  for(int i=0; i < 10; i++){
    digitalWrite(pin_a, numTable[i][0]);
    digitalWrite(pin_b, numTable[i][1]);
    digitalWrite(pin_c, numTable[i][2]);
    digitalWrite(pin_d, numTable[i][3]);
    digitalWrite(pin_e, numTable[i][4]);
    digitalWrite(pin_f, numTable[i][5]);
    digitalWrite(pin_g, numTable[i][6]);
    digitalWrite(pin_p, numTable[i][7]);
    delay(500);
    }
   delay(200);
  // 依次显示 9~0
  for(int i=9; i > 0; i--){
    digitalWrite(pin_a, numTable[i][0]);
    digitalWrite(pin_b, numTable[i][1]);
    digitalWrite(pin_c, numTable[i][2]);
    digitalWrite(pin_d, numTable[i][3]);
    digitalWrite(pin_e, numTable[i][4]);
    digitalWrite(pin_f, numTable[i][5]);
    digitalWrite(pin_g, numTable[i][6]);
    digitalWrite(pin_p, numTable[i][7]);
    delay(500);
    }
    
}

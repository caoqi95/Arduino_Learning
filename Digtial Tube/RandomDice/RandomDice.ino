/*
 * Random Dice 随机骰子
 */
// 设置各段 LED 的引脚
int pin_a = 7;
int pin_b = 6;
int pin_c = 5;
int pin_d = 10;
int pin_e = 11;
int pin_f = 8;
int pin_g = 9;
int pin_p = 4;

int num;

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

void setup(){
  // 设置 4～11 引脚为输出模式
  for (int i = 4; i <= 11; i++)
  {
    pinMode(i, OUTPUT); 
  }
  // 随机种子，初始化随机数生成器
  randomSeed(analogRead(0));
}


// 根据索引显示数字
void showNum(int index){
  digitalWrite(pin_a, numTable[index][0]); //设置a 引脚的电平
  digitalWrite(pin_b, numTable[index][1]); //设置b 引脚的电平
  digitalWrite(pin_c, numTable[index][2]); //设置c 引脚的电平
  digitalWrite(pin_d, numTable[index][3]); //设置d 引脚的电平
  digitalWrite(pin_e, numTable[index][4]); //设置e 引脚的电平
  digitalWrite(pin_f, numTable[index][5]); //设置f 引脚的电平
  digitalWrite(pin_g, numTable[index][6]); //设置g 引脚的电平
  digitalWrite(pin_p, numTable[index][7]); //设置dp引脚的电平

}


void loop(){
  num = random(10); // 产生随机数
  showNum(num); // 显示随机数
  delay(1000);
}

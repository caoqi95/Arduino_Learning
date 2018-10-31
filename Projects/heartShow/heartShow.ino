/*
 * 使用点阵屏实现心动效果
 */

// 设置点阵屏的行
int rows[8] = {4, 9, A5, 7, 3, A4, 2, A2};
// 设置点阵屏的列
int cols[8] = {8, 1, 0, 5, A3, 6, 10, 11};

// 大“心型”的数据
int table1[8][8] =
{
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 0, 0, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
};

// 小“心型”的数据
int table2[8][8] =
{
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
};

void setup() {
  for (int i = 0; i < 8 ; i++){
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i], HIGH); // 将所有负极拉高，熄灭所有的 LED
    }
}

void ledclose() {
  // 将点阵屏正极拉低，负极拉高，开启显示
  for (int i= 0; i < 8; i++){
    digitalWrite(rows[i], LOW);
    digitalWrite(cols[i], HIGH);
    }
}

// 显示心形函数
void showHeart(int temp[8][8]) {
  for (int j=0; j<8; j++){
    digitalWrite(cols[j], LOW);
    for (int i=0; i<8; i++){
      digitalWrite(rows[i], temp[i][j]);
      delayMicroseconds(100);
      }
      digitalWrite(cols[j], HIGH);
      ledclose();
     }
  }


void loop() {
  for (int i=0; i<100; i++){ // 使用 for 循环来完成延时效果
    showHeart(table1);
    }
   for (int i=0; i<100; i++){
    showHeart(table2);
    }

}

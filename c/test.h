#ifndef __TEST_H__
#define __TEST_H__

int right_up(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int MAP[][30], int MAP2[][30]);      //오른쪽 가속 v
int right(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int MAP[][30], int MAP2[][30]);         //오른쪽 이동 v
int left_up(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int MAP[][30], int MAP2[][30]);       //왼쪽 가속 v
int left(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int MAP[][30], int MAP2[][30]);          //왼쪽 이동 v
int up_up(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int MAP[][30], int MAP2[][30]);         //위로 가속 V
int up(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int MAP[][30], int MAP2[][30]);            //위로 이동 V
int down_up(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int MAP[][30], int MAP2[][30]);       //아래로 가속 V
int down(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int MAP[][30], int MAP2[][30]);          //아래로 이동 V
int right1(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int* L_2, int MAP[][30], int MAP2[][30], int* SCORE);//오른으로 차선으로 변경 V
int left1(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int* L, int MAP[][30], int MAP2[][30], int* SCORE); //왼으로 차선 변경
int up1(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int* L, int MAP[][30], int MAP2[][30], int* SCORE);           //위로 차선 변경
int down1(int* A, int* B, int* TEMP, int* DEATH, int* SUC, int* L_2, int MAP[][30], int MAP2[][30], int* SCORE);         //아래로 차선 변경
int light_r(int* L_O, int* L_O2);   
int light_l(int* L_O, int* L_O2);

void maintest();

void Pass_Test_Result(int score);
void Pass_info(void);

#endif
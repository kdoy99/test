#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define COMNUM 4    //랜덤숫자를 4개만 받아야하기 때문에 4로 설정
#define USERNUM 4   //유저 숫자 개수

void inputComNum(int *arr);
void inputUserNum();
void NumCheck();

int main(void)
{  
    srand((int)time(NULL));
    int arr1[COMNUM];
    int arr2[USERNUM];
    int strike=0;
    int out=0;
    int ball=0;

    inputComNum(arr1);

    while(strike < 4 && out < 3){    
    int strike=0;
    int out=0;
    int ball=0;

    inputComNum(arr1);

    while(strike < 4 && out < 3){
        
        strike=0;
        ball=0;
        out=0;

        inputUserNum(arr2);            //사용자 숫자 입력
        
        NumCheck(arr1, arr2, &strike, &ball, &out);     //숫자일치여부판정

        printf("결과:[ %d ]스트라이크 [ %d ]볼 [ %d ]아웃\n",strike ,ball ,out);
    }

    if (strike == 4) {
        printf("축하합니다! 모든 숫자를 맞췄습니다!\n");
    } else if (out == 3) {
        printf("아웃이 3번 나왔습니다. 게임 오버!\n");
    }

    return 0;
    }
}

void inputComNum(int *arr1){
          
    int count = 0;              // 4개의 숫자를 받을때까지의 횟수를 표현하는 변수 count 설정
        
    for(int j=0; j <40; j++)
    {
        printf("=");
    }
    printf("\n");
    printf("숫자야구게임 셋팅중입니다...");
    printf("\n");

    //4개의 숫자를 뽑아야하기때문에 4가 넘으면 while문 종료
    while(count < COMNUM){ 
        int a = rand() % 9+1;   // 1~9까지 랜덤한 숫자를 가지는 변수 a 설정               
        int duplicate = 0;  // 중복체크하는 변수 duplicate

        for(int i=0; i <= a; i++){
            if(arr1[i] == a){                //arr[i] 의 값과 랜덤값을 가지는 a 의 값이 같을 경우 중복변수를 1로 변경하고 break.
                duplicate = 1;      
                break;
            }
        } 
    
        if(duplicate == 0){                  //위 if문의 중복체크에서 걸리지 않았을 경우 배열에 값 넣기.
            arr1[count] = a;
            printf("%d ",arr1[count]);
            count++;
        }
    }
    printf("\n");
    printf("컴퓨터의 숫자 입력이 끝났습니다!!\n");
    printf("\n");
    printf("숫자야구게임 시작!!\n");
    for(int j=0; j <40; j++){
        printf("=");
    }
    printf("\n");   
}

void inputUserNum(int *arr2){

    printf("사용자는 숫자 4 자리를 입력해주세요<숫자를 한칸 씩 띄워서 입력>: \n");
    for(int i=0; i<USERNUM; i++){        
        scanf("%d",&arr2[i]);
    }
}

void NumCheck(int *arr1,int *arr2, int *strike, int *ball, int *out){
    
    int outcount=0;

    for(int i=0; i<COMNUM; i++){       
        for(int j=0; j<USERNUM; j++){

            if(arr1[i] == arr2[j]){  
                if(i == j){
                    (*strike)++;   //같은 배열의 값이 같으면 스트라이크++
                }else{                  
                    (*ball)++;     //for for문을 돌려서 값이 같으면 볼++
                }
            }
            else if(arr1[i] != arr2[j]){
                outcount++;
                if(outcount == 16){     //outcount가 16이면 일치하는게 없다는 뜻 = out++;
                    (*out)++;
                }
            }
        }    
    }
}
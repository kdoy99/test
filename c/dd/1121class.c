// #include <stdio.h>
// // #define ADD 1
// #define MIN 0

// int main(void)
// {
//     int num1, num2;
//     printf("두 개의 정수 입력: ");
//     scanf("%d %d", &num1, &num2);

// #ifdef ADD
//     printf("%d + %d = %d \n", num1, num2, num1+num2);
// #endif

// #ifdef MIN
//     printf("%d - %d = %d \n", num1, num2, num1-num2);
// #endif

//     return 0;
// }


// 파일의 분할

#include <stdio.h>
int num = 0;

void Increment(void)
{
    num++;
}

int GetNum(void)
{
    return num;
}

int main(void)
{
    printf("num: %d \n", GetNum());
    Increment();
    printf("num: %d \n", GetNum());
    Increment();
    printf("num: %d \n", GetNum());
    return 0;
}
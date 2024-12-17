#include <stdio.h>

int main(void)
{
    int a[5][5]={0,};
    int temp[5][5]={0,};
    int i, j;
    int count=4;
    int num = 1;

    for (i = 0; i <= count; i++) // 1번째 배열
    {
        for (j = 0; j <= count; j++)
        {   
            a[i][j] += num;
            printf("%-2d  ", a[i][j]);
            num++;
        }
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < 5; i++) // 2번째 배열
    {
        for (j = 4; j >= 0; j--)
        {
            printf("%-2d  ", a[j][i]);
        }
        printf("\n");
    }
    printf("\n");

    for (i = 4; i >= 0; i--) // 3번째 배열
    {
        for (j = 4; j >= 0; j--)
        {
            printf("%-2d  ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (i = 4; i >= 0; i--) // 4번째 배열
    {
        for (j = 0; j < 5; j++)
        {
            printf("%-2d  ", a[j][i]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

/* 아래는 출력 변화가 아닌 값 변화 시도 */

// for (i = 0; i <= count; i++) // 2번째 배열
//     {
//         for (j = 0; j <= count; j++)
//         {   
//             temp[j][i]=a[count-j][i];
//             printf("%-2d  ", temp[j][i]);
//         }
//         printf("\n");
//     }
//     printf("\n");
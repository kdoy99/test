// // 피라미드1

// #include <stdio.h>
// int main(void)
// {
//     int i, j, k;
//     int num;
//     printf("피라미드 층수를 입력해주세요 : ");
//     scanf("%d", &num);
    
//     for (i=1;i<=num;i++)
//     {
//         for (j=1;j<= num-i;j++)
//         {
//             printf(" ");
//         }
//         for (k=1;k<=(2*i-1);k++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }

//     return 0;
// }


// //피라미드 2
// #include <stdio.h>
// int main(void)
// {
//     int i, j, k;
//     int num;
//     printf("피라미드 층수를 입력해주세요 : ");
//     scanf("%d", &num);
    
//     for (i=0;i<num;i++)
//     {
//         for (j=0;j < i;j++)
//         {
//             printf(" ");
//         }
//         for (k=0;k<(2*(num-i)-1);k++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }

//     return 0;
// }


// // 마름모
// #include <stdio.h>
// int main(void)
// {
//     int i, j, k;
//     int num;
//     printf("마름모 층수를 입력해주세요 : ");
//     scanf("%d", &num);
    
//     for (i=1;i<num;i++)
//     {
//         for (j=1;j<= num-i;j++)
//         {
//             printf(" ");
//         }
//         for (k=1;k<=(2*i-1);k++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
    
//     for (i=0;i<num;i++)
//     {
//         for (j=0;j < i;j++)
//         {
//             printf(" ");
//         }
//         for (k=0;k<(2*(num-i)-1);k++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
// }


// // 모래시계
// #include <stdio.h>
// int main(void)
// {
//     int i, j, k;
//     int num;
//     printf("모래시계 층수를 입력해주세요 : ");
//     scanf("%d", &num);
    
//     for (i=0;i<num-1;i++)
//     {
//         for (j=0;j < i;j++)
//         {
//             printf(" ");
//         }
//         for (k=0;k<(2*(num-i)-1);k++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//     for (i=1;i<=num;i++)
//     {
//         for (j=1;j<= num-i;j++)
//         {
//             printf(" ");
//         }
//         for (k=1;k<=(2*i-1);k++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
// }


// // 스트라이크
// #include <stdio.h>
// int main(void)
// {
//     int i, j, k;
//     int num;
//     printf("스트라이크 층수를 입력해주세요 : ");
//     scanf("%d", &num);
    
//     for (i=0;i<=num;i++)
//     {
//         for (j=0;j < i;j++)
//         {
//             printf("*");
//         }
//         for (k=0;k<(2*(num-i));k++)
//         {
//             printf(" ");
//         }
//         for (j=0;j < i;j++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//     for (i=1;i<=num;i++)
//     {
//         for (j=1;j<= num-i;j++)
//         {
//             printf("*");
//         }
//         for (k=1;k<=(2*i);k++)
//         {
//             printf(" ");
//         }
//         for (j=1;j<= num-i;j++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
// }


// 바람개비
#include <stdio.h>
int main(void)
{
    int i, j, k;
    int num;
    printf("바람개비 층수를 입력해주세요 : ");
    scanf("%d", &num);
    
    for (i=1;i<=num;i++) // 1~10번째 줄
    {
        for (j=1;j <= i;j++)
        {
            printf("* ");
        }
        for (k=1;k<=num-i;k++)
        {
            printf("  ");
        }
        for (j=0;j <= num-i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (i=1;i<=num;i++) // 11~20번째 줄
    {
        for (j=1;j<= num-i;j++)
        {
            printf("  ");
        }
        for (k=1;k<=i;k++)
        {
            printf("* ");
        }
        for (j=1;j<i;j++)
        {
            printf("  ");
        }
        for (k=0;k<=num-i;k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
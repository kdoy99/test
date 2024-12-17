// 1번

// #include <stdio.h>

// int main(void)
// {
//     int i;
//     int a[10];

//     for (i=1;i<11;i++)
//     {
//         a[i-1]=i;
//         printf("a[%d] = %d\n",i-1 ,a[i-1]);
//     }

//     return 0;
// }


// 2번

// #include <stdio.h>

// int main(void)
// {
//     int i;
//     int a[10];

//     for (i=1;i<11;i++)
//     {
//         a[i-1]=i*10;
//     }
//     for (i=9;i>=0;i--)
//     {
//         printf("a[%d] = %d\n", i, a[i]);
//     }

//     return 0;
// }


// 3번

// #include <stdio.h>

// int main(void)
// {
//     int i;
//     int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
//     int temp[10];

//     for (i = 0; i < 5; i++)
//     {
//         temp[i]=a[i];
//         a[i]=a[9-i];
//         a[9-i]=temp[i];
//     }
    
//     for (i = 0; i < 10; i++)
//     {
//         printf("a[%d] = %d\n", i, a[i]);
//     }
    
//     return 0;
// }


// 4번

// #include <stdio.h>

// int main(void)
// {
//     int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
//     int b[10];
//     int i;

//     for (i = 0; i < 10; i++)
//     {
//         b[i] = a[9-i];
//         printf("a[%d] = %d\nb[%d] = %d\n\n", i, a[i], i, b[i]);
//     }

//     return 0;
// }


// 5번

// #include <stdio.h>

// int main(void)
// {
//     int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
//     int b[10];
//     int i;
//     int limit = 10;

//     for (i = 0; i < limit; i++)
//     {
//         if (i==limit-1)
//         {
//             b[i] = a[0];
//             printf("a[%d] = %d\nb[%d] = %d\n\n", i, a[i], i, b[i]);
//         }
//         else
//         {
//             b[i] = a[i+1];
//             printf("a[%d] = %d\nb[%d] = %d\n\n", i, a[i], i, b[i]);
//             continue;
//         }
//     }
    
//     return 0;
// }


// 6번

#include <stdio.h>

int main(void)
{
    int a[9];
    int i;
    int max = 0;
    int limit = 10;

    for (i = 1; i < limit; i++)
    {
        printf("숫자를 입력해주세요 : ");
        scanf("%d", &a[i-1]);
        if (i==1)
        {
            max = a[i-1];
            printf("초기 max 값을 설정합니다.\nmax 값 = %d\n", max);
            continue;
        }
        if (a[i-1] > max)
        {
            max = a[i-1];
            printf("max 값이 변경되었습니다.\n현재 max 값 = %d\n\n", max);
        }
        else
        {
            printf("max 값이 변경되지 않았습니다.\n현재 max 값 = %d\n\n", max);
        }
    }

    printf("최종 max 값 : %d", max);

    return 0;
}
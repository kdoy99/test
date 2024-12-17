// 문제 1

// #include <stdio.h>

// int main(void)
// {
//     int a[10];
//     int i;

//     for (i = 0; i < 10; i++)
//     {
//         printf("정수를 입력해주세요 : ");
//         scanf("%d", &a[i]);
//         if (a[i] % 2 == 1)
//         {
//             printf("정수 %d = 홀수\n", a[i]);
//         }
//         else
//         {
//             printf("정수 %d = 짝수\n", a[i]);
//         }
//     }

//     return 0;    
// }


// 문제 2

// #include <stdio.h>

// int main(void)
// {
//     int a[10];
//     int number;
//     int i;
//     int odd = 0;
//     int even = 0;

//     for (i = 0; i < 10; i++)
//     {
//         printf("정수를 입력해주세요 : ");
//         scanf("%d", &number);
//         if (number % 2 == 1)
//         {
//             a[odd] = number;
//             printf("a[%d] = %d\n", odd, a[odd]);
//             odd += 1;
//         }
//         else
//         {
//             a[9-even] = number;
//             printf("a[%d] = %d\n", 9-even, a[9-even]);
//             even += 1;
//         }
//     }

//     printf("최종 배열 목록\n");

//     for (i = 0; i < 10; i++)
//     {
//         printf("a[%d] = %d\n", i, a[i]);
//     }

//     return 0;
// }


// 문제 3

#include <stdio.h>

int main(void)
{
    int a[10]; // 임시 배열
    int b[10]; // 오름차순 정렬
    int c[10]; // 내림차순 정렬
    int i, j;
    int max_power = 0;
    int min_power = 0;
    int number;

    for (i = 0; i < 10; i++) // 임시로 값 저장하는 배열 선언
    {
        printf("중복되지 않게 정수를 입력해주세요 : ");
        scanf("%d", &a[i]);
    }
    

    for (i = 0; i < 10; i++) // 오름차순 만들기
    {
        for (j = 0; j < 10; j++)
        {
            if (a[i] > a[j])
            {
                max_power += 1; // 큰 수 파워값 측정
            }
        }
        b[9-max_power] = a[i]; // 파워만큼 9에서 빼서 앞자리에 배치해주기
        max_power = 0; // 파워값 초기화
    }
    
    printf("입력하신 정수를 오름차순으로 정렬해드리겠습니다.\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", b[i]);
    }
    
    printf("\n\n");
    for (i = 0; i < 10; i++) // 내림차순 만들기
    {
        for (j = 0; j < 10; j++)
        {
            if (a[i] < a[j])
            {
                min_power += 1; // 작은 수 파워값 측정
            }
        }
        c[9-min_power] = a[i]; // 파워만큼 9에서 빼서 앞자리에 배치해주기
        min_power = 0; // 파워값 초기화
    }

    printf("입력하신 정수를 내림차순으로 정렬해드리겠습니다.\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
    
    return 0;
}
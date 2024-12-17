#include <stdio.h>

int main(void)

// // 20241015 예제 10
// {
//     int a, b, c;


//     while (1)
//     {
//         printf("세 개의 수를 입력하세요 : ");
//         scanf("%d %d %d", &a, &b, &c);
//         if (a==b || b==c || a==c)
//             continue;
//         if (a > b)
//         {
//             if (a > c)
//             {
//                 printf("가장 큰 수는 %d입니다.", a);
//                 break;
//             }
//             else
//             {
//                 printf("가장 큰 수는 %d입니다.", c);
//                 break;
//             }
//         }
//         else if (b > c)
//         {
//             printf("가장 큰 수는 %d입니다.", b);
//             break;
//         }
//         else
//         {
//             printf("가장 큰 수는 %d입니다.", c);
//             break;
//         }
//     }
    
//         return 0;
// }

// // 20241015 예제 11
// {
//     int user;
//     printf("1. 가위 2. 바위 3. 보 \n원하시는 번호를 선택하세요 : ");
//     scanf("%d", &user);
// // 컴퓨터 : 가위
//     while (1)
//     {
//         switch (user)
//         {
//         case 1:
//             printf("유저 : '가위', 컴퓨터 : '가위' \n");
//             printf("비겼습니다.");
//             break;
//         case 2:
//             printf("유저 : '바위', 컴퓨터 : '가위' \n");
//             printf("승리하셨습니다!");
//             break;
//         case 3:
//             printf("유저 : '보', 컴퓨터 : '가위' \n");
//             printf("패배하셨습니다...");
//             break;
//         default:
//             printf("숫자를 입력해주세요");
//             break;
//         }
        
//         return 0;
//     }
// }


// // 20241015 예제 12
// {
//     int user;
//     printf("나이를 입력해주세요. : ");
//     scanf("%d", &user);

//     if (user<8)
//         printf("내실 요금은 0원 입니다. \n");

//     else if (user >= 60)
//         printf("내실 요금은 2,500원 입니다. \n");

//     else
//         printf("내실 요금은 5,000원 입니다. \n");

//     return 0;
// }


// // 20241015 예제 13
// {
//     int user;
//     printf("나이를 입력해주세요. : ");
//     scanf("%d", &user);

//     if (user<8)
//         printf("무료 입장 입니다. \n");

//     else if (user >= 60)
//         printf("무료 입장 입니다. \n");

//     else
//         printf("내실 요금은 5,000원 입니다. \n");

//     return 0;
// }


// // 20241015 예제 14
// {
//     int korean, english, math;
//     printf("국어, 영어, 수학의 점수를 입력해주세요 : ");
//     scanf("%d %d %d", &korean, &english, &math);

//     double average = (korean + english + math) / 3;

//     if(average>=90)
//         printf("학생의 성적은 A입니다. \n");

//     else if(average>=80)
//         printf("학생의 성적은 B입니다. \n");

//     else if(average>=70)
//         printf("학생의 성적은 C입니다. \n");

//     else if(average>=60)
//         printf("학생의 성적은 D입니다. \n");

//     else
//         printf("학생의 성적은 F입니다. 좀 더 노력하세요. \n");
    
//     return 0;
// }


// // 20241016 문제1
// {
//     int a, i;
//     int sum=0;

//     printf("1 이상의 정수를 입력해주세요 : \n");
//     scanf("%d", &a);

//     for (i=1; i<=a; i++)
//     {
//         sum += i;
//     }
//     printf("1부터 %d까지의 합은 %d입니다. \n", a, sum);

//     return 0;
// }


// // 20241016 문제2
// {
//     int i;
//     int sum=0;

//     for(i=1;i<101;i++)
//     {
//         if(i%3==0)
//         {
//             sum+=i;
//         }
//     }
//     printf("%d\n", sum);

//     return 0;
// }


// // 20241016 문제3
// {
//     int num1, num2, i;
//     printf("두 정수를 입력하세요 (단, 두번째로 입력한 수가 더 크게) : \n");
//     scanf("%d %d", &num1, &num2);

//     for(i=1;i<=num1;i++)
//     {
//         if(num1 % i == 0 && num2 % i == 0)
//         {
//             printf("%d ", i);
//         }
//     }

//     return 0;
// }


// // 20241016 문제4
// {
//     int num, i, total;
//     total=0;
//     printf("정수를 입력하세요 : \n");
//     scanf("%d", &num);

//     for (i = 1; i <= num; i++)
//     {
//         if(num%i==0)
//         {
//             printf("%d ", i);
//             total++;
//         }
//     }
//     printf(": %d\n", total);

//     return 0;
// }


// // 문제5
// {
//     int num1, num2, i;
//     printf("두 정수를 입력하세요 (단, 두번째로 입력한 수가 더 크게) : ");
//     scanf("%d %d", &num1, &num2);

//     for (i = num1; i >= 1; i--)
//     {
//         if(num1%i==0 && num2%i==0)
//         {
//             printf("%d, %d 두 수의 최대공약수는 %d입니다.\n", num1, num2, i);
//             break;
//         }
//     }
    
//     return 0;
// }


// // 문제6
// {
//     int i;
//     int sum=0;
    
//     for (i = 1; i < 101; i++)
//     {
//         if(i%2==1)
//         {
//             sum+=i;
//         }
//         else if(i%2==0)
//         {
//             sum-=i;
//         }
//     }
//     printf("%d", sum);

//     return 0;
// }


// 문제7
{
    int num[5];
    int i, j;
    int a=0; // 누가 최고인지 판별

    for (i = 0; i < 5; i++)
    {
        printf("5개의 정수를 입력해주세요 : ");
        scanf("%d", &num[i]);
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++) // n번째 숫자가 1, 2, 3, 4, 5번째 숫자보다 큰지 확인
        {
            if (num[i]>num[j])
            {
                a++; // 본인 포함 자기가 더 큰 숫자다 a 변수에 +1 저장
            }
        }
        if (a==4) // 본인 포함 자기가 4개 숫자보다 더 클 때 작동
        {
            printf("가장 큰 수는 %d입니다.", num[i]);
            break;
        }
        a=0;
    }
    
    return 0;
}
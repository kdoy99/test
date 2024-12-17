#include <stdio.h>
#include <ctype.h>

// int main(void)
// {
//     int dan=0, num=1;
//     printf("몇 단? : ");
//     scanf("%d", &dan);

//     while(num<10)
//     {
//         printf("%d x %d = %d \n", dan, num, dan*num);
//         num++;
//     }
//     return 0;
// }


// {
//     int total=0, num=0;

//     do
//     {
//         printf("정수 입력(0 to quit): ");
//         scanf("%d", &num);
//         total += num;
//     } while (num != 0);
//     printf("합계 : %d \n", total);
//     return 0;    
// }


// {
//     int total=0;
//     int i,num;
//     printf("0부터 num까지의 덧셈, num은? ");
//     scanf("%d", &num);

//     for(i=0; i<num+1; i++)
//         total+=i;

//     printf("0부터 %d까지의 덧셈결과 : %d \n", num, total);
//     return 0;
// }

// {
//     int num;
//     printf("정수 입력 : ");
//     scanf("%d", &num);

//     if(num<0)
//         printf("입력 값은 0보다 작다. \n");
    
//     if(num>0)
//         printf("입력 값은 0보다 크다. \n");
    
//     if(num==0)
//         printf("입력 값은 0이다. \n");

//     return 0;
// }


// // 조건문 or 예제
// {
//     int num;

//     for(num=1; num<100; num++)
//     {
//         if(num%3 == 0 || num%4 == 0)
//             printf("3 또는 4의 배수 : %d \n", num);
//     }
//     return 0;
// }


// // ? : 조건문 예제
// {
//     int num, abs;
//     printf("정수 입력 : ");
//     scanf("%d", &num);

//     abs = num > 0 ? num : num*(-1);
//     printf("절댓값 : %d \n", abs);
//     return 0;
// }


// // 문제 1
// {
//     int i;

//     for(i=1; i<100; i++)
//     {
//         if(i%7==0 || i%9==0)
//         printf("%d ", i);
//     }
//     printf("\n");
//     return 0;
// }


// // 문제 2
// {
//     int num1, num2;
//     printf("두 개의 정수를 입력하세요 : ");
//     scanf("%d %d", &num1, &num2);

//     if(num1>num2)
//         printf("두 정수의 차는 %d입니다. \n", num1 - num2);
//     else if(num2>num1)
//         printf("두 정수의 차는 %d입니다. \n", num2 - num1);
//     else
//         printf("두 정수의 차는 0입니다.");
    
//     return 0;
// }


// // 문제 3
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

//     else if(average>=50)
//         printf("학생의 성적은 D입니다. \n");

//     else
//         printf("학생의 성적은 F입니다. 좀 더 노력하세요. \n");
    
//     return 0;
// }


// // break 예제
// {
//     int sum=0, num=0;

//     while(1)
//     {
//         sum+=num;
//         if(sum>5000)
//             break;
//         num++;
//     }
//     printf("sum: %d \n", sum);
//     printf("num: %d \n", num);
//     return 0;
// }


// // switch case 조건문 예제
// {
//     int num;
//     printf("1이상 5이하의 정수 입력 : ");
//     scanf("%d", &num);

//     switch (num)
//     {
//     case 1:
//         printf("1은 ONE \n");
//         break;
//     case 2:
//         printf("2는 TWO \n");
//         break;
//     case 3:
//         printf("3은 THREE \n");
//         break;
//     case 4:
//         printf("4는 FOUR \n");
//         break;
//     case 5:
//         printf("5는 FIVE \n");
//         break;
//     default:
//         printf("I don't know! \n");
//     }
//     return 0;
// }


// // getchar() 이용
// #define SPACE ' '
// {
//     char ch;

//     ch = getchar();
//     while (ch != '\n')
//     {
//         if (ch == SPACE)
//             putchar(ch);
//         else
//             putchar(ch + 1);
//         ch = getchar();
//     }
//     putchar(ch);

//     return 0;
// }


// // isalpha
// {
//     char ch;

//     while ((ch = getchar()) != '\n')
//     {
//         if (isalpha(ch))
//             putchar(ch+1);
//         else
//             putchar(ch);
//     }
//     putchar(ch);

//     return 0;
// }


// 루프 건너뛰기
// int main(void)
// {
//     const float MIN = 0.0f;
//     const float MAX = 100.0f;

//     float score;
//     float total = 0.0f;
//     int n = 0;
//     float min = MAX;
//     float max = MIN;

//     printf("첫 번째 스코어를 입력하시오(끝내려면 q) : ");
//     while (scanf("%f", &score) == 1)
//     {
//         if (score < MIN || score > MAX)
//         {
//             printf("%0.1f : 유효한 값이 아닙니다. 다시 입력하시오 : ",
//                 score);
//             continue;
//         }
//         printf("%0.1f : 유효한 값입니다. \n", score);
//         min = (score < min)? score : min;
//         max = (score > max)? score : max;
//         total += score;
//         n++;
//         printf("다음 스코어를 입력하시오(끝내려면 q) : ");
//     }
//     if (n > 0)
//     {
//         printf("스코어 %d개의 평균은 %0.1f입니다. \n", n, total / n);
//         printf("최저 = %0.1f, 최고 = %0.1f\n", min, max);
//     }
//     else
//         printf("유효한 값을 전혀 입력하지 않았습니다.\n");
//     return 0;
// }

// #define B "거짓말"
// #define X 10
// int main(void)
// {
//     int age;
//     int xp;
//     char name[40];

//     printf("이름이 뭡니까?");
//     scanf("%s", &name);
//     printf("좋아요, %s 씨, 나이는 얼마죠?\n", name);
//     scanf("%d", &age);
//     xp = age + X;
//     printf("%s! 최소한 %d세는 되어 보이는데.\n", B, xp);
//     return 0;
// }
// {
//     int num;
//     scanf("%s", &num);
//     printf("%d", num);
// }

// 기존 배열을 활용하여 철수, 영희, 짱구의 국영수 성적 입력하기

// #include <stdio.h>

// int main(void)
// {
//     int i, j;

//     char * name[3] = {"철수","영희","짱구"};
//     char * subject[3] = {"국어","영어","수학"};

//     float score[3][3];
//     for (i = 0; i < 3; i++)
//     {
//         printf("%s의 성적을 입력하세요. \n", name[i]);
//         for (j = 0; j < 3; j++)
//         {
//             printf("%s:", subject[j]);
//             scanf("%f", &score[i][j]);
//         }
//     }
    
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             printf("%s의 %s 점수 : %0.2f\n", name[i], subject[j], score[i][j]);
//         }
        
//     }
    
//     return 0;
// }


// 구조체 활용

#include <stdio.h>

typedef struct test
{
    char name[30];
    char subject[100];
    float score;
} Test;

int main(void)
{
    Test result[9];
    int i;

    for (i = 0; i < 9; i++)
    {
        printf("학생의 이름은? : \n");
        scanf("%s", result[i].name);
        printf("과목은? : \n");
        scanf("%s", result[i].subject);
        printf("%s 점수 : \n", result[i].subject);
        scanf("%f", &result[i].score);
    }

    for (i = 0; i < 9; i++)
    {
        printf("%s 학생의 %s 점수는 %0.2f 입니다. \n", result[i].name, result[i].subject, result[i].score);
    }
    
    return 0;    
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RandomExample_Number 40
#define EXAMPLE_AMOUNT 1000
#define EXAMPLE_LENGTH 1000
#define PER_SEC 1000

void clean_str(char *str) {
    size_t length = strlen(str);
    if (length >0 && str[length-1]=='\n') {
        str[length -1] = '\0';
    }
}
void calculate_time(clock_t start, clock_t finish){
    int duration = (finish-start)/PER_SEC;
    printf("문제풀이에 걸린 시간은 %d초 입니다.\n", duration);
}

int main(void)
{
    // 랜덤 숫자 40개 뱉는 파트

    srand((int)time(NULL));

    int number_list[RandomExample_Number]; // 1000문제 랜덤으로 40개 출력
    int i, j;
    int duplicated_number = 0;
    char input_answer[5];                  // 사용자 입력 답
    double total_score = 0;                // 총 점수
    int wrong_count=0;


    for (i = 0; i < RandomExample_Number; i++)
    {
        int random_number = rand() % 1000;
        number_list[i] = random_number;

        for (j = 0; j < RandomExample_Number; j++)
        {
            if (number_list[j] == random_number)
            {
                duplicated_number += 1;
                break;
            }
        }
        if (duplicated_number > 1) {
            number_list[i] = random_number;
            continue;
            //continue에서 break로 수정
        }
        //duplicated_number = 0;
    }

// 랜덤 숫자 40개로, 1000개 문제 중에서 40개 뽑아오는 부분
    //문제파일
    char lines[EXAMPLE_AMOUNT][EXAMPLE_LENGTH];
    int linecount = 0;

    FILE * fp=fopen("car_quest.txt", "rt");
    if(fp==NULL) {
        perror("파일오픈 실패~");
        return -1;
    }

    while (fgets(lines[linecount], EXAMPLE_LENGTH, fp) != NULL)
    {
        linecount++;
        if (linecount >= EXAMPLE_AMOUNT)
            break;
    }

    fclose(fp);
    //정답파일
    char lines_answer[EXAMPLE_AMOUNT][EXAMPLE_LENGTH];
    int answer_count = 0;
    
    FILE * fpp=fopen("car_answer.txt", "rt");
    if (fpp==NULL) {
        perror("파일오픈 실패~");
        return -1;
    }
    while (fgets(lines_answer[answer_count], EXAMPLE_LENGTH, fpp) != NULL)
    {
        answer_count++;
        if (answer_count >= EXAMPLE_AMOUNT)
            break;
    }
    fclose(fpp);

    char wrong_answers[RandomExample_Number][EXAMPLE_LENGTH]; // 오답 담는 배열
    clock_t start = clock();

    for (i = 0; i < RandomExample_Number; i++)
    {
        printf("문제 %d번 %s \n", i+1,lines[number_list[i]]);
        printf("정답 입력 : ");
        scanf("%s", input_answer);
        printf("\n");
        clean_str(input_answer);
        clean_str(lines_answer[number_list[i]]);

        if (strcmp(input_answer, lines_answer[number_list[i]])==0) {//문자열 비교 strcmp
        //정답을 불러온건 2차원 배열인데 입력받은 값은 1차원배열이라 크기가 안맞아서 값을 비교못하나?
            printf("%d번 문제 정답입니다! \n", i+1);
            total_score += 2.5;
        } else {
            printf("%d번 문제 틀렸습니다!!!!!!! \n", i+1);
            strcpy(wrong_answers[wrong_count], lines[number_list[i]]); 
            
            wrong_count++;
        }
        printf("\n");
    }
    clock_t finish = clock();
    calculate_time(start, finish);

    printf("총 점수는 %.1lf 입니다.\n", total_score);



    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define RandomExample_Number 40
#define EXAMPLE_AMOUNT 1000
#define EXAMPLE_LENGTH 1000
#define PER_SEC 1000
#define COUNTTIME 2400


void clean_str(char *str) {
    size_t length = strlen(str);
    if (length >0 && str[length-1]=='\n') {
        str[length -1] = '\0';
    }
}

int main(void)
{
    // 랜덤 숫자 40개 뱉는 파트

    srand((int)time(NULL));

    int number_list[RandomExample_Number];
    int i, j;
    int duplicated_number = 0;
    char input_answer[5];
    double total_score = 0;
    
    //시간 계산 초기화

    

    for (i = 0; i < RandomExample_Number; i++)
    {
        int random_number = rand() % 1000;
        number_list[i] = random_number;
        for (j = 0; j < RandomExample_Number; j++)
        {
            if (number_list[j] == random_number)
            {
                duplicated_number = 1;
                break;
            }
        }
        if (!duplicated_number) {
            number_list[i] = random_number;
            break;
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
        puts("파일오픈 실패~");
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
        puts("파일오픈 실패~");
        return -1;
    }
    while (fgets(lines_answer[answer_count], EXAMPLE_LENGTH, fpp) != NULL)
    {
        answer_count++;
        if (answer_count >= EXAMPLE_AMOUNT)
            break;
    }
    fclose(fpp);


    //제한시간 40분 시험
    printf("            시험을 시작합니다. ");
    time_t start_time = time(NULL); //위치가 중요한가...? 초기화를 밑에 했더니 시간이 이상하게 출력되었음
    
    for (i = 0; i < RandomExample_Number; i++) {   
        time_t current_time = time(NULL);
        int dif_time = difftime(current_time, start_time);
        int remain_time = COUNTTIME - dif_time;
        if (dif_time >= COUNTTIME) {
            printf("시험 시간이 종료되었습니다. 불합격입니다. \n");
            break;
        }
        
        int minute = remain_time / 60;
        int second = remain_time % 60;
        printf("\n------ 남은 시간은 %d분 %d초 입니다.----- \n", minute, second);
        printf("\n");
        printf("문제 %d번 %s \n", i+1,lines[number_list[i]]);
        printf("정답 입력 : ");
        scanf("%s", input_answer);
        clean_str(input_answer);
        clean_str(lines_answer[number_list[i]]);

        if (strcmp(input_answer, lines_answer[number_list[i]])==0) {
            total_score += 2.5;
        } else {

        }
        printf("\n");
        
    }
    printf("총 점수는 %.1lf 입니다.\n", total_score);    
    if (total_score >= 70) {
        printf("축하합니다. 합격입니다.\n");
    } else {
        printf("불합격입니다. 다시 응시해주세요.\n");
    }
    return 0;
}


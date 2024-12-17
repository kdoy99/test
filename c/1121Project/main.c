#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Account_Logic.h"
#include "Test_Logic.h"

#define RandomExample_Number 40
#define EXAMPLE_AMOUNT 1000
#define EXAMPLE_LENGTH 1000
#define PER_SEC 1000
#define COUNTTIME 2400

Change_For_Userinfo ran; // 유저 계정에 따라 변동되는 전역변수 모아놓은 구조체


void clean_str(char *str) { // 문제 인식을 위해 널 문자 없애기
    size_t length = strlen(str);
    if (length >0 && str[length-1]=='\n') {
        str[length -1] = '\0';
    }
}
void calculate_time(clock_t start, clock_t finish){
    int duration = (finish-start)/PER_SEC;
    printf("문제풀이에 걸린 시간은 %d초 입니다.\n", duration);
}
void ID_NAME(int Access_num) // ID 코드에 따른 ID 문자열 반납
{
    FILE * fp = fopen("ID_chest.txt", "rt");
    if (fp==NULL)
    {
        puts("파일오픈 실패!");
    }

    char lines[100][100];
    int i = 0;
    
    while(fgets(lines[i], 100, fp) != NULL)
    {
        lines[i][strlen(lines[i])-1]='\0';
        if (Access_num == i)
        {
            fclose(fp);
            printf("로그인 중인 ID : %s\n", lines[i]);
            strcpy(ran.ID_TEXT, lines[i]);
            break;
        }
        if (feof(fp) != 0)
        {
            fclose(fp);
        }
        i++;
    }
}

void MakeFileName(void)  // 파일 이름 만들어서 전역변수에 할당
{
    char TempName[100];
    char Name_WrongNote[100] = "_wrongNote.txt"; // 파일 이름 1
    char Name_WrongNote_Answer[100] = "_wrongNote_answer.txt"; // 파일 이름 2
    char Name_Practice_Test[100] = "_Practice_Test_Result.txt"; // 파일 이름 3
    char Pass_info[100] = "_Pass_info.txt"; // 파일 이름 4
    // char Success_info[100] = "_Success_info.txt" // 파일 이름 5, 실기시험 합치고 추가
    
    strcpy(TempName, ran.ID_TEXT);
    strcat(TempName, Name_WrongNote);
    
    strcpy(ran.Filename1, TempName); // 파일 이름 1 생성 (닉네임_오답노트.txt)

    strcpy(TempName, ran.ID_TEXT);
    strcat(TempName, Name_WrongNote_Answer);
    
    strcpy(ran.Filename2, TempName); // 파일 이름 2 생성 (닉네임_오답노트_답안.txt)

    strcpy(TempName, ran.ID_TEXT);
    strcat(TempName, Name_Practice_Test);
    
    strcpy(ran.Filename3, TempName); // 파일 이름 3 생성 (닉네임_모의테스트 점수.txt)

    strcpy(TempName, ran.ID_TEXT);
    strcat(TempName, Pass_info);
    
    strcpy(ran.Filename4, TempName); // 파일 이름 4 생성 (닉네임_실전테스트 합격정보.txt)

    // strcpy(TempName, ran.ID_TEXT);
    // strcat(TempName, Success_info);
    
    // strcpy(ran.Filename5, TempName); // 파일 이름 5 생성 (닉네임_실기시험 합격정보.txt)

}

void Practice_Test_Result(double total_score)
{
    char score[10];
    sprintf(score, "%.1f", total_score);

    FILE * fp = fopen(ran.Filename3, "at");

    fputs(score, fp);
    fputs("\n", fp);
    fclose(fp);
    
    printf("점수를 저장합니다.\n");
}

void Print_Test_Result()
{
    int i = 0;
    char lines[1000][10];
    FILE * fp = fopen(ran.Filename3, "rt");

    while(fgets(lines[i], 10, fp) != NULL)
    {
        printf("%d번째 모의시험 결과 : %s점 \n", i+1, lines[i]);
        i++;
    }
        
    fclose(fp);
}

void Create_Pass_info() // 계정 생성과 동시에 합격/불합격 정보 파일 생성
{
    FILE * fp = fopen(ran.Filename4, "wt");
    char text[10] = "불합격";

    fputs(text, fp);
    fclose(fp);
}

void Append_WrongNote() // 오답노트 생성, 추가
{
    FILE * fp = fopen(ran.Filename1, "at");

    fputs(ran.Temp_WrongQuest, fp);
    fclose(fp);

}

void Append_WrongNote_Answer() // 오답노트 답안 생성, 추가
{
    FILE * fp = fopen(ran.Filename2, "at");
    
    fputs(ran.Temp_WrongAnswer, fp);
    fputs("\n",fp);
    fclose(fp);
}

void Temp_wrongnote()
{
    FILE * fp = fopen("Temp.txt", "at");

    fputs(ran.Temp_WrongQuest, fp);
    fputs("\n", fp);
    fclose(fp);

    FILE * fp2 = fopen("Temp_answer.txt", "at");

    fputs(ran.Temp_WrongAnswer, fp2);
    fputs("\n", fp2);
    fclose(fp2);
}

int Wrong_Line_Count()
{
    FILE * fp = fopen(ran.Filename1, "rt");
    int count = 0;
    char lines[1000][1000];

    while(fgets(lines[count], 1000, fp) != NULL)
        count++;
            
    fclose(fp);

    ran.Temp_WrongLines = count;
}

void Pass_Test()
{
    FILE * fp = fopen(ran.Filename4,"wt");
    char text[10] = "합격";

    fputs(text, fp);
    fclose(fp);
}

int Check_Pass()
{
    FILE * fp = fopen(ran.Filename4,"rt");
    char text[10];
    char pass[10] = "합격";
    char non_pass[10] = "불합격";
    int count = 0; // 1은 합격 0은 불합격 뜻함

    fgets(text,10,fp);

    if (strcmp(text, pass)==0)
    {
        count+=1;
        return (int)count;
    }
    else if (strcmp(text, non_pass)==0)
    {
        return (int)count;
    }
    
}

void File_Copy()
{
    FILE * fp1 = fopen("Temp.txt", "rt");
    FILE * fp2 = fopen(ran.Filename1, "wt");
    char str[EXAMPLE_LENGTH];


    while((fgets(str, sizeof(str), fp1)) != NULL)
        fputs(str, fp2);
    
    if(feof(fp1) != 0)
        puts("파일복사 완료!");
    else
        puts("파일복사 실패!");

    fclose(fp1);
    fclose(fp2);

    FILE * fp3 = fopen("Temp_answer.txt", "rt");
    FILE * fp4 = fopen(ran.Filename2, "wt");
    char str2[10];


    while((fgets(str2, sizeof(str2), fp3)) != NULL)
        fputs(str2, fp4);
    
    if(feof(fp3) != 0)
        puts("파일복사 완료!");
    else
        puts("파일복사 실패!");

    fclose(fp3);
    fclose(fp4);
}

// void RandomNumbers()
// {
//     srand((int)time(NULL));
// }

// void Practice_Test()

// void Real_Test()

int main(void)
{
    // 랜덤 숫자 40개 뱉는 파트

    srand((int)time(NULL));

    int number_list[RandomExample_Number];
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
            }
        }
        if (duplicated_number > 1)
        {
            continue;
        }
        duplicated_number = 0;
    }

// 랜덤 숫자 40개로, 1000개 문제 중에서 40개 뽑아오는 부분

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

    for (i = 0; i < EXAMPLE_AMOUNT; i++)
    {
        printf;
    }
    

    // 로그인 화면

    while (1)
    {   
        Login lo; //구조체

        int Access_num = -1; // 로그인 성공 후, 몇번째 계정에 로그인 중인지 들고가야 할 값 (0도 아이디이므로 -1로 저장)

        printf("번호를 입력해주세요 : 1. 로그인 / 2. 회원가입 \n");
        scanf("%d", &lo.chooseIDorNEW);

        if (lo.chooseIDorNEW == 1) // 로그인 선택
        {
            printf("ID : ");
            scanf("%s", lo.userInput);
            ran.ID_CODE = ID_Check(lo.userInput);
            if (ran.ID_CODE == 10000 || ran.ID_CODE == 0)
            {
                printf("없는 아이디입니다! 회원가입을 해주세요. \n");
                continue;
            }
            else
            {
                while (1)
                {
                    printf("비밀번호를 입력해주세요 (취소하려면 cancel) : ");
                    scanf("%s", lo.PasswordInput);
                    int PASSWORD_CODE = PASSWORD_Check(lo.PasswordInput, ran.ID_CODE);
                    printf("ID : %d, PW : %d", ran.ID_CODE, PASSWORD_CODE); // 추후 삭제
                    if (ran.ID_CODE == PASSWORD_CODE)
                    {
                        printf("로그인 성공! \n");
                        Access_num = ran.ID_CODE;
                        ID_NAME(Access_num); // ID 코드 및 텍스트 전역변수에 할당
                        MakeFileName(); // ID의 값을 토대로 오답노트용 파일 생성
                        Create_Pass_info();
                        break;
                    }
                    else if (PASSWORD_CODE == 100000)
                    {
                        printf("처음 화면으로 돌아갑니다. \n");
                        break;
                    }
                    else
                    {
                        printf("틀린 비밀번호입니다. 제대로 된 비밀번호를 입력해주세요. \n");
                        continue;
                    }
                }
            }
        }
        else if (lo.chooseIDorNEW == 2) // 회원가입 선택
        {
            while (1)
            {
                char Temp_New_ID_Input[100];

                printf("새로운 ID를 입력해주세요 (100자 이내) : \n");
                scanf("%s", lo.New_ID_Input);
                
                strcpy(Temp_New_ID_Input, lo.New_ID_Input);

                int NIC = New_ID_Create(lo.New_ID_Input);
                if (NIC == -2) // 중복 아이디 감지
                {
                    printf("이미 존재하는 ID입니다. \n");
                    continue;
                }
                else if (NIC == -3)
                {
                    printf("중복되지 않는 ID입니다! \n");
                }
                printf("비밀번호를 입력해주세요 (100자 이내) : \n");
                scanf("%s", lo.New_PW_Input);
                New_PW_Create(lo.New_PW_Input);

                WrongNote(lo.New_ID_Input);
                WrongNote_Answer(Temp_New_ID_Input);

                printf("회원가입이 완료되었습니다. ID : %s, PW : %s \n", lo.New_ID_Input, lo.New_PW_Input);
                break;
            }
        }
        else
        {
            continue;
        }

        if (Access_num >= 0) // 로그인 성공하고 들어가는 곳
        {
            while (1)
            {
                int ChooseKindOfTest;
                int Theory_num;
                int Practice_num;

                printf("1. 필기시험 / 2. 실기시험 \n");
                scanf("%d", &ChooseKindOfTest);

                if (ChooseKindOfTest == 1) // 1. 필기시험 선택
                {
                    printf("1. 모의시험 / 2. 오답노트 / 3. 실전 테스트 / 4. 모의 테스트 결과 모음\n");
                    scanf("%d", &Theory_num);
                    Theory_Test(Theory_num);
                    while (1)
                        if (Theory_num == 1) // 1. 모의시험 선택
                        {
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

                                if (strcmp(input_answer, lines_answer[number_list[i]])==0)
                                {
                                    printf("%d번 문제 정답입니다! \n", i+1);
                                    total_score += 2.5;
                                }
                                else
                                {
                                    printf("%d번 문제 틀렸습니다!!!!!!! \n", i+1);
                                    strcpy(wrong_answers[wrong_count], lines[number_list[i]]);
                                    strcpy(ran.Temp_WrongQuest, lines[number_list[i]]);
                                    strcpy(ran.Temp_WrongAnswer, lines_answer[number_list[i]]);

                                    Append_WrongNote(); // 현재 로그인 한 계정의 오답노트에 오답 추가 (ID값과 문제 번호 가져감)
                                    Append_WrongNote_Answer();
                                    
                                    wrong_count++;
                                }
                                printf("\n");
                            }
                            clock_t finish = clock();
                            calculate_time(start, finish);

                            printf("총 점수는 %.1lf 입니다.\n", total_score);
                            Practice_Test_Result(total_score);


                            break;
                        }
                        else if (Theory_num == 2) // 2. 오답노트
                        {
                            Wrong_Line_Count(); // 오답 몇 문제 저장중인지 값 받고 시작
                            char lines_Tn_Q[ran.Temp_WrongLines][EXAMPLE_LENGTH];
                            i = 0;
                            
                            FILE * fppppp = fopen(ran.Filename1, "rt");

                            while(fgets(lines_Tn_Q[i], EXAMPLE_LENGTH, fppppp) != NULL)
                            {
                                if (feof(fppppp) != 0)
                                {
                                    puts("오답노트 파일의 끝입니다.");
                                }
                                i++;
                            }
                            fclose(fppppp);

                            char lines_Tn_A[ran.Temp_WrongLines][EXAMPLE_LENGTH];
                            i = 0;

                            FILE * fp2=fopen(ran.Filename2, "rt");
                            
                            while (fgets(lines_Tn_A[i], EXAMPLE_LENGTH, fp2) != NULL)
                            {
                                lines_Tn_A[i][strlen(lines_Tn_A[i])-1]='\0';
                                if (feof(fp2) != 0)
                                {
                                    fclose(fp);
                                }
                                i++;
                            }

                            for (i = 0; i < ran.Temp_WrongLines; i++)
                            {
                                char Tn_input_answer[10];
                                
                                printf("문제 %d번 %s \n", i+1,lines_Tn_Q[i]);
                                printf("정답 입력 : ");
                                scanf("%s", Tn_input_answer);
                                printf("\n");
                                clean_str(input_answer);
                                clean_str(lines_Tn_Q[i]);
                                int YorN;

                                while (1)
                                {
                                    if (strcmp(Tn_input_answer, lines_Tn_A[i])==0)
                                    {
                                        printf("오답노트 %d번 문제 정답입니다! \n", i+1);
                                        printf("정답을 맞춘 오답노트를 삭제하시겠습니까? (1. Yes / 2. No) \n");
                                        scanf("%d", &YorN);
                                        if (YorN == 1) 
                                        {
                                            break;
                                        }
                                        else if (YorN == 2) // strcpy 써서 데이터 삭제 구현 (문제 파일 + 답 파일)
                                        {
                                            strcpy(ran.Temp_WrongQuest, lines_Tn_Q[i]);
                                            strcpy(ran.Temp_WrongAnswer, lines_Tn_A[i]);
                                            Temp_wrongnote();
                                            break;
                                        }
                                        else
                                        {
                                            continue;
                                        }
                                    }
                                    else
                                    {
                                        printf("틀렸습니다.\n");

                                        strcpy(ran.Temp_WrongQuest, lines_Tn_Q[i]);
                                        strcpy(ran.Temp_WrongAnswer, lines_Tn_A[i]);
                                        Temp_wrongnote();
                                        break;
                                    }
                                    i++;
                                }
                                  
                            }

                            File_Copy();
                            remove("Temp.txt");
                            remove("Temp_answer.txt");
                            break;
                        }
                        else if (Theory_num == 3)
                        {
                            /* code */
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
                                Pass_Test();
                                break;
                            } else {
                                printf("불합격입니다. 다시 응시해주세요.\n");
                                break;
                            }

                        }
                        else if (Theory_num == 4)
                        {
                            Print_Test_Result();
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    
                }
                else if (ChooseKindOfTest == 2)
                {
                    while (1)
                    {
                        int Pass_info_number = Check_Pass();
                        if (Pass_info_number == 1)
                        {
                            printf("실기시험 시작!\n");
                            break;
                        }
                        else if (Pass_info_number == 0)
                        {
                            printf("먼저 필기시험을 합격하고 와주세요.\n");
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                else
                {
                    continue;
                }
            }
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>


#include "Account_Logic.h"
#include "test.h"


#define RandomExample_Number 40 // 문제 개수
#define EXAMPLE_AMOUNT 1000 // 문제량
#define EXAMPLE_LENGTH 1000 // 문제 텍스트 인식 범위
#define PER_SEC 10001
#define COUNTTIME 2400

Change_For_Userinfo ran; // 유저 계정에 따라 변동되는 전역변수 모아놓은 구조체


void clean_str(char *str) { // 문제 인식을 위해 널 문자 없애기
    size_t length = strlen(str);
    if (length >0 && str[length-1]=='\n') {
        str[length -1] = '\0';
    }
}
void calculate_time(clock_t start, clock_t finish){ // 시간초 계산
    int duration = (finish-start)/PER_SEC;
    printf("문제풀이에 걸린 시간은 %d초 입니다.\n", duration);
}



void ID_NAME(int Access_num) // 1. ID 코드에 따른 ID 문자열 반납
{
    FILE * fp = fopen("ID_chest.txt", "rt");

    char lines[100][100];
    int i = 0;
    
    while(fgets(lines[i], 100, fp) != NULL)
    {
        lines[i][strlen(lines[i])-1]='\0';
        if (Access_num == i)
        {
            fclose(fp);
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

void MakeFileName(void)  // 2. 파일 이름 만들어서 전역변수에 할당
{
    char TempName[100];
    char Name_WrongNote[100] = "_wrongNote.txt"; // 파일 이름 1
    char Name_WrongNote_Answer[100] = "_wrongNote_answer.txt"; // 파일 이름 2
    char Name_Practice_Test[100] = "_Practice_Test_Result.txt"; // 파일 이름 3
    char Pass_info[100] = "_Pass_info.txt"; // 파일 이름 4
    char Success_info[100] = "_Success_info.txt"; // 파일 이름 5, 실기시험 합치고 추가
    
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

    strcpy(TempName, ran.ID_TEXT);
    strcat(TempName, Success_info);
    
    strcpy(ran.Filename5, TempName); // 파일 이름 5 생성 (닉네임_실기시험 합격정보.txt)

}

void Practice_Test_Result(double total_score) // 3. 모의테스트 점수 유저별로 저장
{
    char score[10];
    sprintf(score, "%.1f", total_score);

    FILE * fp = fopen(ran.Filename3, "at");

    fputs(score, fp);
    fputs("\n", fp);
    fclose(fp);
}

void Print_Test_Result() // 4. 저장한 모의테스트 점수 출력하기
{
    int i = 0;
    char lines[1000][100];
    FILE * fp = fopen(ran.Filename3, "rt");

    char first = fgetc(fp);
    if (first == EOF)
    {
        printf("모의 테스트를 치른 기록이 없습니다! \n");
        return;
    }
    

    while(fgets(lines[i], 10, fp) != NULL)
    {
        printf("%d번째 모의시험 점수 : %s", i+1, lines[i]);
        i++;
    }
        
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
    char text[100];
    char pass[100] = "합격";
    char non_pass[100] = "불합격";
    int count = 0; // 1은 합격 0은 불합격 뜻함

    fgets(text,100,fp);

    if (strcmp(text, pass) == 0)
    {
        count = 1;
        return (int)count;
    }
    else if (strcmp(text, non_pass)==0)
    {
        return (int)count;
    }
    
}

void Save_Test_Result()
{
    FILE * fp = fopen(ran.Filename5,"wt");
    FILE * fp2 = fopen("score.txt", "rt");

    char pass[100] = "실기시험 합격 정보 : 합격, 점수 : ";
    char score[10];

    fgets(score, 10, fp2);
    strcat(pass, score);

    fputs(pass, fp);

    fclose(fp);
    fclose(fp2);
}

void Read_User_Info()
{
    FILE * fp_t = fopen(ran.Filename4, "rt");
    FILE * fp_r = fopen(ran.Filename5, "rt");

    char text_1[100];
    char text_2[100];

    fgets(text_1, 100, fp_t);
    fgets(text_2, 100, fp_r);

    printf("필기시험 합격 정보 : %s \n", text_1);
    printf("%s \n", text_2);

    fclose(fp_t);
    fclose(fp_r);
}

void File_Copy()
{
    FILE * temp_file = fopen("Temp.txt", "rt");
    FILE * fp = fopen(ran.Filename1, "wt");
    char str[EXAMPLE_LENGTH];


    while((fgets(str, sizeof(str), temp_file)) != NULL)
        fputs(str, fp);

    fclose(temp_file);
    fclose(fp);

    FILE * temp_file_answer = fopen("Temp_answer.txt", "rt");
    FILE * fp_answer = fopen(ran.Filename2, "wt");
    char str2[10];


    while((fgets(str2, sizeof(str2), temp_file_answer)) != NULL)
        fputs(str2, fp_answer);
    

    fclose(temp_file_answer);
    fclose(fp_answer);
}

void Test_40_RandomNumbers(int Theory_num) // 랜덤한 문제 40개 가져오기, 이 문제를 토대로 모의 테스트와 실전 테스트 보기
{

    // 랜덤 숫자 40개 뱉는 파트

    srand((int)time(NULL));

    int i, j;
    int number_list[RandomExample_Number];
    int duplicated_number = 0;

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

    // 문제 1000개 배열에 저장

    char lines[EXAMPLE_AMOUNT][EXAMPLE_LENGTH];
    int lines_count = 0;

    FILE * quest = fopen("car_quest.txt", "rt");

    while (fgets(lines[lines_count], EXAMPLE_LENGTH, quest) != NULL)
    {
        lines_count++;
        if (lines_count >= EXAMPLE_AMOUNT)
            break;
    }
    fclose(quest);

    // 문제 답 1000개 배열에 저장

    char lines_answer[EXAMPLE_AMOUNT][EXAMPLE_LENGTH];
    int lines_answer_count = 0;
    
    FILE * answer=fopen("car_answer.txt", "rt");

    while (fgets(lines_answer[lines_answer_count], EXAMPLE_LENGTH, answer) != NULL)
    {
        lines_answer_count++;
        if (lines_answer_count >= EXAMPLE_AMOUNT)
            break;
    }
    fclose(answer);

    
    
    // 문제 1000개에서, 랜덤 번호 40개 넣어서 문제 뽑아오기

    clock_t start = clock();

    char input_answer[5];                  // 사용자 입력 답

    int wrong_count=0; // 오답 횟수

    double total_score = 0;                // 총 점수

    if (Theory_num == 1) // 모의테스트
    {
        for (i = 0; i < RandomExample_Number; i++)
        {
            printf("문제 %d번 %s \n", i+1,lines[number_list[i]]); // 랜덤 문제 40개
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

                strcpy(ran.Temp_WrongQuest, lines[number_list[i]]); // 전역변수, 오답문제 저장
                strcpy(ran.Temp_WrongAnswer, lines_answer[number_list[i]]); // 전역변수, 오답문제의 답 저장

                Append_WrongNote(); // 현재 로그인 한 계정의 오답노트에 오답 추가 (ID값과 문제 번호 가져감)
                Append_WrongNote_Answer(); // 현재 로그인 한 계정의 오답노트 답 파일에 답 추가 (ID값과 문제 답안 번호 가져감)
                
                wrong_count++; // 파일 읽을 범위 정하기 위해 카운트 +1
            }
            printf("\n");
        }
        clock_t finish = clock();
        calculate_time(start, finish);

        printf("총 점수는 %.1lf 입니다.\n", total_score);
        Practice_Test_Result(total_score);
    }
    else if (Theory_num == 3) // 실전테스트
    {
        //제한시간 40분

        printf("            시험을 시작합니다. ");
        time_t start_time = time(NULL); 
        
        for (i = 0; i < RandomExample_Number; i++)
        {
            
            // 시간 관련
            time_t current_time = time(NULL);
            int dif_time = difftime(current_time, start_time);
            int remain_time = COUNTTIME - dif_time;
            if (dif_time >= COUNTTIME)
            {
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

            if (strcmp(input_answer, lines_answer[number_list[i]])==0) // 맞추면 2.5점 추가, 틀리면 그냥 넘어감
            {
                total_score += 2.5;
            }

            printf("\n");
            
        }
        printf("총 점수는 %.1lf 입니다.\n", total_score);
        if (total_score >= 70)
        {
            printf("축하합니다. 합격입니다.\n");
            printf("실기시험에 응시할 수 있습니다! \n");
            Pass_Test();
        }
        else
        {
            printf("불합격입니다. 다시 응시해주세요.\n");
        }
    }
    
}

void Wrong_Note() // 오답노트 총정리 함수
{
    char lines_Wnote[ran.Temp_WrongLines][EXAMPLE_LENGTH];
    int i = 0;
    
    
    FILE * fp = fopen(ran.Filename1, "rt");

    char first = fgetc(fp);
    if (first == EOF)
    {
        printf("오답노트가 비어있습니다! \n");
        return;
    }

    while(fgets(lines_Wnote[i], EXAMPLE_LENGTH, fp) != NULL)
    {
        i++;
    }
    fclose(fp);

    char lines_Wnote_answer[ran.Temp_WrongLines][EXAMPLE_LENGTH];
    i = 0;

    FILE * fp_answer = fopen(ran.Filename2, "rt");
    
    while (fgets(lines_Wnote_answer[i], EXAMPLE_LENGTH, fp_answer) != NULL)
    {
        lines_Wnote_answer[i][strlen(lines_Wnote_answer[i])-1]='\0';
        i++;
    }

    for (i = 0; i < ran.Temp_WrongLines; i++)
    {
        char input_answer[10];
        
        printf("문제 %d번 %s \n", i+1,lines_Wnote[i]);
        printf("정답 입력 : ");
        scanf("%s", input_answer);
        printf("\n");

        clean_str(input_answer);
        clean_str(lines_Wnote[i]);

        while (1)
        {
            if (strcmp(input_answer, lines_Wnote_answer[i]) == 0) // 오답노트 맞췄을 시
            {
                int YorN;

                printf("오답노트 %d번 문제 정답입니다! \n", i+1);
                printf("정답을 맞춘 오답노트를 삭제하시겠습니까? (1. Yes / 2. No) \n");
                scanf("%d", &YorN);

                if (YorN == 1) 
                {
                    break;
                }
                else if (YorN == 2) // strcpy 써서 데이터 삭제 구현 (문제 파일 + 답 파일)
                {
                    strcpy(ran.Temp_WrongQuest, lines_Wnote[i]);
                    strcpy(ran.Temp_WrongAnswer, lines_Wnote_answer[i]);
                    Temp_wrongnote();
                    break;
                }
                else // 제대로 된 숫자 입력될 때까지 무한반복
                {
                    continue;
                }
            }
            else // 틀렸다
            {
                printf("틀렸습니다.\n");

                strcpy(ran.Temp_WrongQuest, lines_Wnote[i]);
                strcpy(ran.Temp_WrongAnswer, lines_Wnote_answer[i]);
                Temp_wrongnote();
                break;
            }
        }
    }

    File_Copy();
    remove("Temp.txt");
    remove("Temp_answer.txt");
}

int main(void)
{
    // 로그인 화면

    while (1)
    {   
        Login lo; //구조체

        int Access_num = -1; // 로그인 성공 후, 몇번째 계정에 로그인 중인지 들고가야 할 값 (0도 아이디이므로 -1로 저장)

        printf("번호를 입력해주세요 : 1. 로그인 / 2. 회원가입 / 3. 종료 \n");
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
                    if (ran.ID_CODE == PASSWORD_CODE)
                    {
                        printf("로그인 성공! \n");
                        Access_num = ran.ID_CODE;
                        ID_NAME(Access_num); // ID 코드 및 텍스트 전역변수에 할당
                        printf("%s 님 환영합니다. \n", ran.ID_TEXT);
                        MakeFileName(); // ID의 값을 토대로 오답노트용 파일 생성
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
                char cancel_Text[10] = "cancel";

                printf("새로운 ID를 입력해주세요 (100자 이내, 취소하려면 cancel) : \n");
                scanf("%s", lo.New_ID_Input);
                if (strcmp(cancel_Text, lo.New_ID_Input) == 0)
                {
                    printf("처음 화면으로 돌아갑니다.\n");
                    break;
                }
                
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

                WrongNote(Temp_New_ID_Input);
                strcpy(Temp_New_ID_Input, lo.New_ID_Input);

                WrongNote_Answer(Temp_New_ID_Input);
                strcpy(Temp_New_ID_Input, lo.New_ID_Input);

                Create_Pass_info(Temp_New_ID_Input);
                strcpy(Temp_New_ID_Input, lo.New_ID_Input);

                Create_Success_info(Temp_New_ID_Input);
                strcpy(Temp_New_ID_Input, lo.New_ID_Input);

                Create_Practice_info(Temp_New_ID_Input);
                strcpy(Temp_New_ID_Input, lo.New_ID_Input);

                printf("회원가입이 완료되었습니다. ID : %s, PW : %s \n", Temp_New_ID_Input, lo.New_PW_Input);
                break;
            }
        }
        else if (lo.chooseIDorNEW == 3)
        {
            break;
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

                printf("1. 필기시험 / 2. 실기시험 / 3. 합격 정보 조회 / 4. 로그아웃 \n");
                scanf("%d", &ChooseKindOfTest);

                if (ChooseKindOfTest == 1) // 1. 필기시험 선택
                {
                    while (1)
                    {
                        int Theory_num;

                        printf("1. 모의시험 / 2. 오답노트 / 3. 실전 테스트 / 4. 모의 테스트 결과 모음 / 5. 뒤로 가기 \n");
                        scanf("%d", &Theory_num);
                        if (Theory_num == 1) // 1. 모의시험 선택
                        {
                            Test_40_RandomNumbers(Theory_num);
                            break;
                        }
                        else if (Theory_num == 2) // 2. 오답노트
                        {
                            Wrong_Line_Count(); // 오답 몇 문제 저장중인지 값 받고 시작
                            Wrong_Note();
                        }
                        else if (Theory_num == 3)
                        {
                            Test_40_RandomNumbers(Theory_num);
                            break;
                        }
                        else if (Theory_num == 4)
                        {
                            Print_Test_Result();
                            break;
                        }
                        else if (Theory_num == 5)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                else if (ChooseKindOfTest == 2) // 실기시험 선택
                {
                    while (1)
                    {
                        int Pass_info_number = Check_Pass();
                        if (Pass_info_number == 1)
                        {
                            printf("실기시험 시작!\n");
                            maintest();
                            
                            Save_Test_Result();

                            break;
                        }
                        else if (Pass_info_number == 0)
                        {
                            printf("먼저 필기시험을 합격하고 와주세요.\n");
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else if (ChooseKindOfTest == 3) // 필기, 실기 합격 정보 출력
                {
                    Read_User_Info();
                    continue;
                }
                
                else if (ChooseKindOfTest == 4) // 로그아웃
                {
                    printf("다음에 또 뵙겠습니다. \n");
                    break;
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
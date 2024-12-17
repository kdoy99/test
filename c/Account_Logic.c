#include <stdio.h>
#include <string.h>

int ID_Check(char * userInput) // 로그인 - ID 입력란
{
    FILE * fp=fopen("ID_chest.txt", "rt"); // ID 정보들이 들어있는 파일 오픈
    if (fp==NULL)
    {
        puts("파일오픈 실패");
        return -1;
    }

    char lines[100][100]; // id
    int i = 0;
    int failed = 10000;
    while(fgets(lines[i], 100, fp) != NULL)    
    {
        lines[i][strlen(lines[i])-1]='\0';
        if (!strcmp(userInput, lines[i]))
        {   
            fclose(fp);
            return (int)i;
        }
        if (feof(fp) != 0)
        {
            fclose(fp);
            return (int)failed;
        }
        i++;
    }
}

int PASSWORD_Check(char * userInput, int ID_CODE) // 로그인 - 비밀번호 입력란
{
    FILE * fp=fopen("PASSWORD_chest.txt", "rt"); // PASSWORD 정보들이 들어있는 파일 오픈
    if (fp==NULL)
    {
        puts("파일오픈 실패");
        return -1;
    }

    char lines[100][100];
    int i = 0;
    int j = ID_CODE; // 비밀번호가 중복일 수도 있으므로 체크
    int failed = 10000;
    char cancel_keyword[100] = "cancel";
    int cancel = 100000;
    
    if (!strcmp(userInput, cancel_keyword))
    {
        fclose(fp);
        return (int)cancel;
    }
    

    while(fgets(lines[i], 100, fp) != NULL)    
    {
        lines[i][strlen(lines[i])-1]='\0';
        if (!strcmp(userInput, lines[i]) && i == j) // 입력한 비밀번호가 비밀번호 파일에 있고, 저장 위치까지 동일하면?
        {   
            fclose(fp);
            return (int)i;
        }
        if (feof(fp) != 0)
        {
            fclose(fp);
            return (int)failed;
        }
        i++;
    }  
}


int New_ID_Create(char * userInput) // 회원가입 - ID
{
    FILE * fp=fopen("ID_chest.txt", "rt");
    if (fp==NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }

    char lines[100][100]; // id
    int i = 0;
    int duplicate = -2; // 중복 ID 감지시 이 값을 리턴

    while(fgets(lines[i], 100, fp) != NULL) // 중복 ID 검사
    {
        lines[i][strlen(lines[i])-1]='\0';
        if (!strcmp(userInput, lines[i]))
        {
            fclose(fp);
            return (int)duplicate; // 중복일시 리턴값 반환하고 종료
        }
        if (feof(fp) != 0)
        {
            fclose(fp);
        }
        i++;
    }

    fp = fopen("ID_chest.txt", "at");
    if (fp==NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }
    
    fputs(userInput, fp);
    fputs("\n", fp);
    fclose(fp);
    return -3;
}


void New_PW_Create(char * userInput) // 회원가입 - 비밀번호
{
    FILE * fp = fopen("PASSWORD_chest.txt", "at");
    if (fp==NULL)
    {
        puts("파일오픈 실패!");
    }
    
    fputs(userInput, fp);
    fputs("\n", fp);
    fclose(fp);
}

void WrongNote(char * New_ID_Input) // 계정 생성과 동시에 오답노트 생성
{
    char filename[100] = "_wrongNote.txt";

    strcat(New_ID_Input, filename);
    FILE * fp = fopen(New_ID_Input, "wt");

    fclose(fp);
}

void WrongNote_Answer(char * New_ID_Input) // 계정 생성과 동시에 오답노트 답지 생성
{
    char filename[100] = "_wrongNote_answer.txt";
    strcat(New_ID_Input, filename);
    FILE * fp = fopen(New_ID_Input, "wt");
    if (fp==NULL)
    {
        puts("파일오픈 실패!");
    }

    fclose(fp);
}

void Create_Pass_info(char * New_ID_Input) // 계정 생성과 동시에 합격/불합격 정보 파일 생성
{
    char filename[100] = "_Pass_info.txt";
    strcat(New_ID_Input, filename);
    FILE * fp = fopen(New_ID_Input, "wt");
    char text[10] = "불합격";

    fputs(text, fp);
    fclose(fp);
}

void Create_Success_info(char * New_ID_Input) // 계정 생성과 동시에 실기시험 합격 정보 생성
{
    char filename[100] = "_Success_info.txt";
    strcat(New_ID_Input, filename);
    FILE * fp = fopen(New_ID_Input, "wt");
    char text[100] = "실기시험 현재 정보 : 불합격";

    fputs(text, fp);
    fclose(fp);
}

void Create_Practice_info(char * New_ID_Input) // 계정 생성과 동시에 모의테스트 결과 파일 생성
{
    char filename[100] = "_Practice_Test_Result.txt";
    strcat(New_ID_Input, filename);
    FILE * fp = fopen(New_ID_Input, "wt");
    
    fclose(fp);
}
#ifndef __ACCOUNT_LOGIC_H__
#define __ACCOUNT_LOGIC_H__

int ID_Check(char * userInput); // 로그인 - ID 입력란
int PASSWORD_Check(char * userInput, int ID_CODE); // 로그인 - 비밀번호 입력란

int New_ID_Create(char * userInput); // 회원가입 - ID
void New_PW_Create(char * userInput); // 회원가입 - 비밀번호

void WrongNote(char * New_ID_Input); // 계정 생성과 동시에 오답노트 생성
void WrongNote_Answer(char * New_ID_Input); // 계정 생성과 동시에 오답노트 답지 생성
void Create_Pass_info(char * New_ID_Input);
void Create_Success_info(char * Temp_New_ID_Input);
void Create_Practice_info(char * Temp_New_ID_Input);



// 로그인 입력 관련 구조체
typedef struct {
    int chooseIDorNEW; // 로그인 or 회원가입 입력란
    char userInput[100]; // 사용자 입력값 받는 곳
    char PasswordInput[100]; // 비밀번호 입력값 받는 곳
    char New_ID_Input[100]; // 새로운 ID 입력값 받는 곳
    char New_PW_Input[100]; // 새로운 PW 입력값 받는 곳
} Login;

// 유저 정보에 따라 바뀌는 전역변수 구조체
typedef struct {
    int Temp_WrongLines;
    int ID_CODE;
    char ID_TEXT[100];
    char Temp_WrongQuest[1000];
    char Temp_WrongAnswer[100];
    char Filename1[100]; // 오답노트 이름
    char Filename2[100]; // 오답노트 답안 이름
    char Filename3[100]; // 모의테스트 점수 저장 파일 이름
    char Filename4[100]; // 실전테스트 합격 정보 저장 파일 이름
    char Filename5[100]; // 실기 합격 정보 저장 파일 이름
} Change_For_Userinfo;

#endif
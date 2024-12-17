// 파일 쓰기 wt

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char head[100];
//     char txt[100] = ".txt";
//     printf("파일명 입력 : \n");
//     scanf("%s", head);
//     strcat(head, txt);

//     FILE * fp=fopen(head,"wt");
//     if(fp==NULL) {
//         puts("파일오픈 실패~");
//         return -1;
//     }

//     fputc('A', fp);
//     fputc('B', fp);
//     fputc('C', fp);
//     fclose(fp);
//     return 0;
// }


// 파일 읽기 rt

// #include <stdio.h>

// int main(void)
// {
//     FILE * fp=fopen("data.txt", "rt");
//     if(fp==NULL) {
//         puts("파일오픈 실패~");
//         return -1;
//     }

//     int ch, i; // 읽기
//     for (i = 0; i < 3; i++)
//     {
//         ch = fgetc(fp);
//         printf("%c \n", ch);
//     }


//     fclose(fp);
//     return 0;
// }


// read

// #include <stdio.h>

// int main(void)
// {
//     char str[30];
//     int ch;
//     FILE * fp = fopen("simple.txt", "rt");
//     if(fp==NULL) {
//         puts("파일오픈 실패!");
//         return -1;
//     }

//     ch=fgetc(fp);
//     printf("%c \n", ch);
//     ch=fgetc(fp);
//     printf("%c \n", ch);

//     fgets(str, sizeof(str), fp);
//     printf("%s", str);
//     fgets(str, sizeof(str), fp);
//     printf("%s", str);

//     fclose(fp);
//     return 0;
// }


// copy

#include <stdio.h>

int main(void)
{
    FILE * src = fopen("src.txt", "rt");
    FILE * des = fopen("dst.txt", "wt");
    char str[20];

    if(src==NULL || des==NULL) {
        puts("파일오픈 실패!");
        return -1;
    }

    while((fgets(str, sizeof(str), src))!=NULL)
        fputs(str, des);
    
    if(feof(src)!=0)
        puts("파일복사 완료!");
    else
        puts("파일복사 실패!");

    fclose(src);
    fclose(des);

    return 0;
}


// 파일이동

// #include <stdio.h>

// int main(void)
// {
//     // 파일생성
//     FILE * fp=fopen("text.txt", "wt");
//     fputs("123456789", fp);
//     fclose(fp);

//     // 파일개방
//     fp=fopen("text.txt", "rt");

//     // SEEK_END test
//     fseek(fp, -2, SEEK_END);
//     putchar(fgetc(fp));

//     // SEEK_SET test
//     fseek(fp, 2, SEEK_SET);
//     putchar(fgetc(fp));

//     // SEEK_CUR test
//     fseek(fp, 2, SEEK_CUR);
//     putchar(fgetc(fp));

//     fclose(fp);
//     return 0;
// }


// 현재 파일 위치 지시자 정보 확인

// #include <stdio.h>

// int main(void)
// {
//     long fpos;
//     int i;

//     FILE * fp = fopen("text.txt", "wt");
//     fputs("1234-", fp);
//     fclose(fp);

//     fp=fopen("text.txt", "rt");

//     for (i = 0; i < 4; i++)
//     {
//         putchar(fgetc(fp));
//         fpos=ftell(fp);
//         fseek(fp,-1,SEEK_END);
//         putchar(fgetc(fp));
//         fseek(fp, fpos, SEEK_SET);
//     }
//     fclose(fp);
//     return 0;
// }


// 동적 할당

// #include <stdio.h>

// char * ReadUserName(void)
// {
//     char name[30];
//     printf("What's your name? ");
//     gets(name);
//     return name;
// }

// int main(void)
// {
//     char * name1;
//     char * name2;
//     name1=ReadUserName();
//     printf("name1: %s \n", name1);
//     name2=ReadUserName();
//     printf("name2: %s \n", name2);
//     return 0;
// }


// int형 배열 선언 (malloc, free 사용)

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int * ptr1 = (int *)malloc(sizeof(int));
//     int * ptr2 = (int *)malloc(sizeof(int)*7);
//     int i;

//     *ptr1 = 20;
//     for (i = 0; i < 7; i++)
//         ptr2[i]=i+1;

//     printf("%d \n", *ptr1);
//     for (i = 0; i < 7; i++)
//         printf("%d ", ptr2[i]);

//     free(ptr1);
//     free(ptr2);
//     return 0;
// }


// 확인

// #include <stdio.h>
// #include <stdlib.h>

// char * ReadUserName(void)
// {
//     char * name = (char *)malloc(sizeof(char)*30);
//     printf("What's your name? ");
//     gets(name);
//     return name;
// }

// int main(void)
// {
//     char * name1;
//     char * name2;
//     name1=ReadUserName();
//     printf("name1: %s \n", name1);
//     name2=ReadUserName();
//     printf("name2: %s \n", name2);

//     printf("again name1: %s \n", name1);
//     printf("again name2: %s \n", name2);
//     free(name1);
//     free(name2);
//     return 0;
// }


// 동적 할당 문제 1

// #include <stdio.h>

// int main(void)
// {
//     int max;
    
//     printf("문자열의 최대길이를 정해주세요 : ");
//     scanf("%d",&max);

//     char words[max];

//     printf("%d만큼 문자열을 정하셨습니다. 이 안에 들어갈 문자열을 작성해주세요. \n", max);
//     fgets(words, sizeof(words), stdin);

//     printf("결과를 출력합니다. %s \n", words);
//     return 0;
// }


// 포인터 함수

// #include <stdio.h>

// void SimpleAdder(int n1, int n2)
// {
//     printf("%d + %d = %d \n", n1, n2, n1+n2);
// }

// void ShowString(char * str)
// {
//     printf("%s \n", str);
// }

// int main(void)
// {
//     char * str="Function Pointer";
//     int num1=10, num2=20;

//     // void (*fptr1)(int, int) = SimpleAdder; // 포인터로 불러본 함수
//     // void (*fptr2)(char *) = ShowString;

//     // fptr1(num1, num2);
//     // fptr2(str);

//     SimpleAdder(num1, num2); // 이게 더 짧아서 좋은데요? 한다면 밑의 문제 참조
//     ShowString(str);
//     return 0;
// }


// 포인터 함수 예제 2 -> 함수 안에 함수를 호출해서 쓴다는게 메리트

// #include <stdio.h>

// int WhoIsFirst(int age1, int age2, int (*cmp)(int n1, int n2))
// {
//     return cmp(age1, age2);
// }

// int OlderFirst(int age1, int age2)
// {
//     if(age1>age2)
//         return age1;
//     else if(age1<age2)
//         return age2;
//     else
//         return 0;
// }

// int YoungerFirst(int age1, int age2)
// {
//     if(age1<age2)
//         return age1;
//     else if(age1>age2)
//         return age2;
//     else
//         return 0;
// }

// int main(void)
// {
//     int age1=20;
//     int age2=30;
//     int first;

//     printf("입장순서 1 \n");
//     first=WhoIsFirst(age1, age2, OlderFirst);
//     printf("%d세와 %d세 중 %d세가 먼저 입장! \n\n", age1, age2, first);

//     printf("입장순서 2 \n");
//     first=WhoIsFirst(age1, age2, YoungerFirst);
//     printf("%d세와 %d세 중 %d세가 먼저 입장! \n\n", age1, age2, first);
//     return 0;
// }


// void에 대한 이해

// 전역변수

// #include <stdio.h>
// void Add(int val);
// int num;

// int main(void)
// {
//     printf("num: %d \n", num);
//     Add(3);
//     printf("num: %d \n", num);
//     num++;
//     printf("num: %d \n", num);
//     return 0;
// }

// void Add(int val)
// {
//     num += val;
// }

// static : 메모리 차지하기 때문에 잘 쓰지 않음

// #include <stdio.h>

// void SimpleFunc(void)
// {
//     static int num1 = 0;
//     int num2 = 0;
//     num1++, num2++;
//     printf("static: %d, local: %d \n", num1, num2);
// }

// int main(void)
// {
//     int i;
//     for (i = 0; i < 3; i++)
//     {
//         SimpleFunc();
//     }
//     return 0;
// }


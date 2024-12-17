// #include <stdio.h>
// #define MSG "I am symbolic string constant."
// #define MAXLENGTH 81


// int main(void)
// {
//     char words[MAXLENGTH]="I am a string in an array.";
//     const char * pt1 = "Something is pointing at me.";
//     puts("Here are some stings:");
//     puts(MSG);
//     puts("words");
//     puts("pt1");
//     words[8]='p';
//     puts(words);

//     return 0;
// }


// #define MSG "I'm special."

// #include <stdio.h>
// int main()
// {
//     char ar[] = MSG;
//     const char *pt = MSG;
//     printf("address of \"I'm special\": %p \n", "I'm special");
//     printf("                address ar: %p \n", ar);
//     printf("                address pt: %p \n", pt);
//     printf("            address of MSG: %p \n", MSG);
//     printf("address of \"I'm special\": %p \n", "I'm special");

//     return 0;
// }


// #include <stdio.h>
// int main(void)
// {
//     const char *mesg = "섣불리 판단하지 말라!";
//     const * copy;
//     copy = mesg;
//     printf("%s\n", copy);
//     printf("mesg = %s; &mesg = %p; 값 = %p\n",
//             mesg, &mesg, mesg);
//     printf("copy = %s; &copy = %p; 값 = %p\n",
//             copy, &copy, copy);
//     return 0;
// }


// #include <stdio.h>
// #define STLEN 10
// int main(void)
// {
//     char words[STLEN];
//     puts("문자열을 입력하세요 (탈출하려면 빈 행):");
//     while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
//     {
//         fputs(words, stdout);
//     } 
//     puts("종료.");

//     return 0;
// }


// #include <stdio.h>
// #define STLEN 10
// int main(void)
// {
//     char words[STLEN];
//     int i;

//     puts("문자열을 입력하세요 (탈출하려면 빈 행): ");
//     while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
//     {
//         i = 0;
//         while (words[i] != '\n' && words[i] != '\0')
//         {
//             i++;
//         }
//         if (words[i] == '\n')
//             words[i] = '\0';
//         else
//             while (getchar() != '\n')
//             {
//                 continue;
//             }
//         puts(words);
//     }
//     puts("종료.");
//     return 0;
// }


// #include <stdio.h>
// int main(void)
// {
//     char name1[11], name2[11];
//     int count;
//     printf("2개의 이름을 입력하시오 : ");
//     count = scanf("%5s %10s", name1, name2);
//     printf("%d개의 이름을 읽었습니다. %s 그리고 %s. \n", count, name1, name2);

//     return 0;
// }


// #include <stdio.h>
// void put1(const char *);
// int put2(const char *);

// int main(void)
// {
//     put1("마음대로 쓸 수 있을 만큼");
//     put1("돈이 풍족하면 참 좋으련만,\n");
//     printf("나는 %d개의 문자들을 카운트했다.\n",
//         put2("나는 수리할 구식 의자들로 울지는 않을 것이다."));

//     return 0;
// }

// void put1(const char *string)
// {
//     while (*string)
//         putchar(*string++);
// }

// int put2(const char * string)
// {
//     int count  = 0;
//     while (*string)
//     {
//         putchar(*string++);
//         count++;
//     }
//     putchar('\n');

//     return(count);   
// }


// strncat 함수 사용

// #include <stdio.h>
// #include <string.h>
// #define SIZE 80
// char * s_gets(char * st, int n);
// int main(void)
// {
//     char flower[SIZE];
//     char addon[]="s smell like old shoes.";

//     puts("네가 가장 좋아하는 꽃이 뭐냐?");
//     if (s_gets(flower, SIZE))
//     {
//         strcat(flower, addon);
//         puts(flower);
//         puts(addon);
//     }
//     else
//         puts("End of file encountered!");
//     puts("안녕");

//     return 0;
// }

// char *s_gets(char*st, int n)
// {
//     char *ret_val;
//     int i = 0;

//     ret_val = fgets(st, n, stdin);
//     if (ret_val)
//     {
//         while (st[i] != '\n' && st[i] != '\0')
//             i++;
//         if (st[i] == '\n')
//         {
//             st[i] = '\0';
//         }
//         else
//             while (getchar() != '\n')
//                 continue;
//     }
//     return ret_val;
// }


// strcmp 함수 사용

// #include <stdio.h>
// #include <string.h>

// #define ANSWER "Grant"
// #define MAX 40
// char * s_gets(char *st, int n);

// int main(void)
// {
//     char try[MAX];

//     puts("Grant의 무덤에 누가 잠들어 있습니까?");
//     s_gets(try, MAX);
//     while (strcmp(try, ANSWER) != 0)
//     {
//         puts("틀렸습니다. 다시 말해 보십시오.");
//         s_gets(try, MAX);
//     }
//     puts("맞았습니다!");

//     return 0;
// }

// char * s_gets(char *st, int n)
// {
//     char * ret_val;
//     int i = 0;

//     ret_val = fgets(st, n, stdin);
//     if (ret_val)
//     {
//         while (st[i] != '\n' && st[i] != '\0')
//             i++;
//         if (st[i] == '\n')
//             st[i] = '\0';
//         else
//             while (getchar() != '\n')
//                 continue;
//     }
//     return ret_val;
// }



// strcmp 함수 사용 2

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     printf("strcmp (\"A\", \"A\") 은 ");
//     printf("%d\n", strcmp("A", "A"));
// }


// strncmp 함수 사용

// #include <stdio.h>
// #include <string.h>
// #define LISTSIZE 6
// int main()
// {
//     const char * list[LISTSIZE] =
//     {
//         "astronomy", "astounding",
//         "astrophysics", "ostracize",
//         "asterism", "astrophobia"
//     };

//     int count = 0;
//     int i;

//     for (i=0; i<LISTSIZE; i++)
//         if (strncmp(list[i],"astro",5)==0)
//         {
//             printf("찾았다 : %s\n", list[i]);
//             count++;
//         }
//     printf("astro로 시작하는 단어를 %d개"
//             "찾았다.\n", count);

//     return 0;
// }


// strcpy 함수

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char str1[20] = "1234567890";
//     char str2[20];
//     char str3[5];

//     // case 1
//     strncpy(str2, str1);
//     puts(str2);

//     // case 2
//     strncpy(str3, str1, sizeof(str3));
//     puts(str3);

//     // case 3
//     strncpy(str3, str1, sizeof(str3)-1);
//     str3[sizeof(str3)-1]=0;
//     puts(str3);
//     return 0;
// }


// str

// #include <stdio.h>
// #include <stalib.h>

// int main(void)
// {
//     char str[20];
//     printf("정수 입력: ");
//     scanf("%s", str);
//     printf("%d \n", atoi(str));

//     printf("실수 입력: ");
//     scanf("%s", str);
//     printf("%g \n", atof(str));
//     return 0;
// }


// ans 1
// strlen

#include <stdio.h>
#include <string.h>

int ConvToInt(char c)
{
    static int diff = 1 - '1';
    int result = c + diff;
    return result;
}

int main()
{
    char str[50];
    int len, i;
    int sum = 0;

    printf("문자열 입력: ");
    fgets(str, sizeof(str), stdin);
    len = strlen(str);
    for(i=0; i<len; i++)
    {
        if('1'<=str[i] && str[i]<='9')
            sum += ConvToInt(str[i]);
    }
    printf("합: %d", sum);
    return 0;
}

// ans 2
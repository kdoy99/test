#include <stdio.h>

int ABClogic(int a, int b, int c)
{
    int result = a + b + c;

    if (result == 6)
    {
        return result;
    }
    else if (result == 7)
    {
        return "hi";
    }
    else if (result == 8)
    {
        return result;
    }

}

int main(void)
{
    int a=1;
    int b=2;
    int c=4;
    char str[100];
    char pass[100] = "abc";
    int * pass_result;
    pass_result = &pass;

    int num = ABClogic(a, b, c);

    printf("%d", num);
    printf("\n문자 입력 : ");
    scanf("%s", str);

    int * str_result;
    str_result = &str;


    while (1)
    {
        if (str_result == pass_result)
        {
            printf("통과");
            break;
        }
    }
    
    
    
}
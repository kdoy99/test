// #include <stdio.h>
// int main(void)
// {
//     int ch;

//     while ((ch=getchar())!=EOF)
//         putchar(ch);

//     return 0;
// }


// #include <stdio.h>
// #define NAME "GIGATHINK, INC."
// #define ADDRESS "101 Megabuck Plaza"
// #define PLACE "Megapolis, CA 94904"
// #define WIDTH 40

// void starbar(void);

// int main(void)
// {
//     starbar();
//     printf("%s\n", NAME);
//     printf("%s\n", ADDRESS);
//     printf("%s\n", PLACE);
//     starbar();

//     return 0;
// }

// void starbar(void)
// {
//     int count;
//     for (count=1;count<=WIDTH;count++)
//         putchar('*');
//     putchar('\n');
// }


// #include <stdio.h>
// #include <string.h>
// #define NAME "GIGATHINK, INC."
// #define ADDRESS "101 Megabuck Plaza"
// #define PLACE "Megapolis, CA 94904"
// #define WIDTH 40
// #define SPACE ' '

// void show_n_char(char ch, int num);

// int main(void)
// {
//     int spaces;

//     show_n_char('*',WIDTH);
//     putchar('\n');
//     show_n_char(SPACE,12);
//     printf("%s\n",NAME);
//     spaces=(WIDTH-strlen(ADDRESS))/2;

//     show_n_char(SPACE,spaces);
//     printf("%s\n",ADDRESS);
//     show_n_char(SPACE, (WIDTH-strlen(PLACE)) /2);

//     printf("%s\n", PLACE);
//     show_n_char('*', WIDTH);
//     putchar('\n');

//     return 0;                                                                                                                                                                                                                                    
// }

// void show_n_char(char ch, int num)
// {
//     int count;

//     for (count=1;count<=num;count++)
//         putchar(ch);
// }


// #include <stdio.h>
// int imin(int,int);

// int main(void)
// {
//     int evil1, evil2;

//     printf("두 정수를 입력하시오(끝내려면 q) : \n");
//     while (scanf("%d %d", &evil1, &evil2)==2)
//     {
//         printf("(%d, %d)에서 작은 것은 %d\n",
//             evil1, evil2, imin(evil1,evil2));
//         printf("두 정수를 입력하시오(끝내려면 q) : \n");
//     }
//     printf("종료!\n");

//     return 0;
// }

// int imin(int n, int m)
// {
//     int min;

//     if (n<m)
//         min=n;
//     else
//         min=m;

//     return min;
// }


// #include <stdio.h>
// long fact(int n);
// long rfact(int n);
// int main(void)
// {
//     int num;

//     printf("이 프로그램은 계승을 계산합니다.");
//     printf("0-12 범위의 한 값을 입력하시오(끝내려면 q) :\n");
//     while(scanf("%d",&num)==1)
//     {
//         if (num<0)
//             printf("음수는 계승이 정의되지 않습니다.");
//         else if (num > 13)
//             printf("13 미만을 입력하시오. \n");
//         else
//         {
//             printf("루프 : %d! = %ld\n",
//                 num, fact(num));
//             printf("재귀 : %d! = %ld\n",
//                 num,rfact(num));
//         }
//         printf("0-12 범위의 한 값을 입력하시오(끝내려면 q):\n");
//     }
//     printf("종료!\n");

//     return 0;
// }    

// long fact(int n)
// {
//     long ans;

//     for (ans=1;n>1;n--)
//         ans *= n;

//     return ans;
// }

// long rfact(int n)
// {
//     long ans;

//     if (n>0)
//         ans=n*rfact(n-1);
//     else
//         ans=1;

//     return ans;
// }


// #include <stdio.h>
// void mikado(int);
// int main(void)
// {
//     int pooh = 2, bah = 5;

//     printf("main()에 있는 pooh = %d, &pooh = %p\n",
//             pooh, &pooh);
//     printf("main()에 있는 bah = %d, &bah = %p\n",
//             bah, &bah);
//     mikado(pooh);

//     return 0;
// }

// void mikado(int bah)
// {
//     int pooh = 10;

//     printf("mikado()에 있는 pooh = %d, &pooh = %p\n",
//             pooh, &pooh);
//     printf("mikado()에 있는 bah = %d, &bah = %p\n",
//             bah, &bah);
// }


// #include <stdio.h>
// void interchange(int u, int v);

// int main(void)
// {
//     int x = 5, y = 10;

//     printf("교환 전 x = %d, y = %d\n", x, y);
//     interchange(x, y);
//     printf("교환 후 x = %d, y = %d\n", x, y);

//     return 0;
// }

// void interchange(int u, int v)
// {
//     int temp;

//     printf("교환 전 u = %d, v = %d\n", u, v);
//     temp = u;
//     u = v;
//     v = temp;
//     printf("교환 후 u = %d, v = %d\n", u, v);

// }


// #include <stdio.h> // test //
// int main(void)
// {
//     int a = 100;
//     int ptr;
//     ptr = &a;
//     printf("%d", ptr);
// }


// #include <stdio.h>
// void interchange(int *u, int *v);

// int main(void)
// {
//     int x = 5, y = 10;

//     printf("교환 전 x = %d, y = %d\n", x, y);
//     interchange(&x, &y);
//     printf("교환 후 x = %d, y = %d\n", x, y);

//     return 0;
// }

// void interchange(int *u, int *v)
// {
//     int temp;

//     printf("교환 전 u = %d, v = %d\n", u, v);
//     temp = *u;
//     *u = *v;
//     *v = temp;
//     printf("교환 후 u = %d, v = %d\n", u, v);

// }


// #include <stdio.h>

// int main(void)
// {
//     int num1 = 15;
//     int num2 = 30;
//     int num3 = 45;

//     int* ptr1 = &num1;
//     int* ptr2 = &num2;
//     int* ptr3 = &num3;

//     ptr1 = ptr2;
//     ptr2 = ptr3;

//     *ptr3 *= 2;
//     *ptr1 += *ptr3;
//     *ptr2 *= 2;

//     printf("%d %d %d", num1, num2, num3);

//     return 0;
// }


// #include <stdio.h>

// int main(void)
// {
//     int num1 = 10;
//     int num2 = 20;
//     int * ptr1 = &num1;
//     int * ptr2 = &num2;
    
//     *ptr1 += 10;
//     *ptr2 -= 10;

//     int * a = ptr1;
//     ptr1 = ptr2;
//     ptr2 = a;

//     printf("%d %d", num1, num2);
// }


// #include <stdio.h>
// #define SIZE 4
// int main(void)
// {
//     int value1 = 44;
//     int arr[SIZE];
//     int value2 = 88;
//     int i;

//     printf("value1 = %d, value2 = %d\n", value1, value2);
//     for (i=-1; i<=SIZE; i++)
//         arr[i]=2*i+1;
//     for (i=-1;i<7;i++)
//         printf("%2d %d\n", i, arr[i]);
//     printf("value1 = %d, value2 = %d\n", value1, value2);
//     printf("arr[-1]의 주소 : %p\n", &arr[-1]);
//     printf("arr[4]의 주소 : %p\n", &arr[4]);
//     printf("value1의 주소 : %p\n", &value1);
//     printf("value2의 주소 : %p\n", &value2);
    
//     return 0;
// }


#include <stdio.h>

// int main()
// {
//     int urn[5] = {100, 200, 300, 400, 500};
//     int* ptr1;
//     int* ptr2;
//     int* ptr3;

//     ptr1 = urn;
//     ptr2 = &urn[2];
//     ptr3 = ptr1 +4;
//     printf("%d\n", *ptr3);
//     ptr1++;
//     printf("%d\n", *ptr1++);
//     ptr2--;
//     printf("%d\n", *ptr2--);
//     --ptr1;
//     printf("%d\n", *--ptr1);
//     ++ptr2;
//     printf("%d\n", *++ptr2);

//     return 0;
// }


// #include <stdio.h>

// int main(void)
// {
//     char str1[]="My String";
//     char * str2 = "Your String";
//     printf("%s %s \n", str1, str2);

//     str1[0]='X';
//     printf("%s %s \n", str1, str2);
//     str2[0]='X';
//     printf("%s %s \n", str1, str2);
//     return 0;
// }



#include <stdio.h>

int main(void)
{
    int list[5]={1,2,3,4,5};
    int *a = list;

    char apple[] = "Apple is delicious";
    char * banana = "Banana is long";
    apple[*(a+2)] = 'B';
    printf("%d %d %s %s",*(apple+2),*(banana+2), apple, banana+2);

    return 0;
}
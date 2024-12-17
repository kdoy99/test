#include <stdio.h>

int main(void)
{
    int num = 10;
    int * ptr1 = &num;
    int * ptr2 = ptr1;

    (*ptr1)++;
    (*ptr2)++;
    printf("%d \n", num);
    return 0;
}

// int main(void)
// {
//     int num1 = 10;
//     int num2 = 20;
//     int * ptr1;
//     int * ptr2;
//     ptr1=&num1;
//     ptr2=&num2;
//     *ptr1+=10;
//     *ptr2-=10;

//     int * temp;
//     temp=ptr1;
//     ptr1=ptr2;
//     ptr2=temp;

//     printf("%d %d", num1, num2);
//     return 0;
// }
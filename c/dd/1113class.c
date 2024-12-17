// #include <stdio.h>

// int main(void)
// {
//     double num = 3.14;
//     double *ptr = &num;
//     double **dptr = &ptr;
//     double *ptr2;

//     printf("%9p %9p \n", ptr, *dptr);
//     printf("%9g %9g \n", num, **dptr);
//     ptr2 = *dptr;
//     *ptr2 = 10.99;
//     printf("%9g %9g \n", num, **dptr);

//     return 0;
// }

// #include <stdio.h>

// void SwapIntPtr(int **dp1, int **dp2)
// {
//     int *temp = *dp1;
//     *dp1 = *dp2;
//     *dp2 = temp;
// }
// int main(void)
// {
//     int num1 = 10, num2 = 20;
//     int *ptr1, *ptr2;
//     ptr1 = &num1, ptr2 = &num2;
//     printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);

//     SwapIntPtr(&ptr1, &ptr2);
//     printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);

//     return 0;
// }


// 이중포인터 예제 복습 필요

// #include <stdio.h>

// int main(void)
// {
//     int num1;
//     int num2;
//     int* p;
//     int* q;
//     int* r;
//     int** pp;

//     num1 = 10;
//     num2 = 20;

//     p = &num1;
//     q = &num2;
//     r = &num1;

//     pp = &p; // &num1의 주소
//     *pp = q; // *(&p) = &num2 -> p = &num2
//     **pp = 1024; // **(&p) = 1024 -> *(&num2) = 1024 -> num2 = 1024
//     pp = &r; // 
//     **pp = *p * 2; // **(&r) = *(&num2) * 2
//                    // *(&num1) = 1024 * 2 -> num1 = 2048
//     printf("%d %d %d %d", pp, *pp, *q, **pp);

//     return 0;
// }


// #include <stdio.h>

// int main(void)
// {
//     int arr1[2][2]={
//         {1, 2}, {3, 4}
//     };
//     int arr2[3][2]={
//         {1, 2}, {3, 4}, {5, 6}
//     };
//     int arr3[4][2]={
//         {1, 2}, {3, 4}, {5, 6}, {7, 8}
//     };

//     int (*ptr)[2];
//     int i;

//     ptr = arr1;
//     printf("** Show 2,2 arr1 **\n");
//     for (i = 0; i < 2; i++)
//     {
//         printf("%d %d \n", ptr[i][0], ptr[i][1]);
//     }

//     ptr = arr2;
//     printf("** Show 3,2 arr2 **\n");
//     for (i = 0; i < 3; i++)
//     {
//         printf("%d %d \n", ptr[i][0], ptr[i][1]);
//     }

//     ptr = arr3;
//     printf("** Show 4,2 arr3 **\n");
//     for (i = 0; i < 4; i++)
//     {
//         printf("%d %d \n", ptr[i][0], ptr[i][1]);
//     }

//     return 0;
// }


#include <stdio.h>

void ShowArr2DStyle(int (*arr)[4], int column)
{
    int i, j;
    for (i = 0; i < column; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
}

int Sum2DArr(int arr[][4], int column)
{
    int i, j, sum = 0;
    for (i = 0; i < column; i++)
    {
        for (j = 0; j < 4; j++)
        {
            sum += arr[i][j];
        }
        return sum;
    }
}

int main(void)
{
    int arr1[2][4] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[3][4] = {1, 1, 1, 1, 3, 3, 3, 3, 5, 5, 5, 5};

    ShowArr2DStyle(arr1, sizeof(arr1)/sizeof(arr1[0]));
    ShowArr2DStyle(arr2, sizeof(arr2)/sizeof(arr2[0]));
    printf("arr1의 합: %d \n", Sum2DArr(arr1, sizeof(arr1)/sizeof(arr1[0])));
    printf("arr2의 합: %d \n", Sum2DArr(arr2, sizeof(arr2)/sizeof(arr2[0])));
    return 0;
}


// 문제1

// #include <stdio.h>

// int main(void)
// {
//     int * arr1[5];
//     int * arr2[3][5];

//     int ** ptr1 = arr1;
//     int *(*ptr2)[5] = arr2;
// }

// 문제2

// #include <stdio.h>


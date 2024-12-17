// #include <stdio.h>

// void ShowArayElem(int * param, int len)
// {
//     int i;
//     for (i = 0; i < len; i++)
//     {
//         printf("%d ", param[i]);
//     }
//     printf("\n");
// }
// int main(void)
// {
//     int arr1[3]=(1, 2, 3);
//     int arr2[5]=(4,5,6,7,8);
//     ShowArayElem(arr1, sizeof(arr1) / sizeof(int));
//     ShowArayElem(arr2, sizeof(arr2) / sizeof(int));
//     return 0;
// }


// #include <stdio.h>

// void ShowArayElem(int * param, int len)
// {
//     int i;
//     for(i=0;i<len;i++)
//         printf("%d ", param[i]);
//     printf("\n");
// }

// void AddArayElem(int * param, int len, int add)
// {
//     int i;
//     for (i = 0; i < len; i++)
//         param[i] += add;
// }

// int main(void)
// {
//     int arr[3]={1, 2, 3};
//     AddArayElem(arr, sizeof(arr) / sizeof(int),1 );
//     ShowArayElem(arr, sizeof(arr) / sizeof(int));
    
//     AddArayElem(arr, sizeof(arr) / sizeof(int),2 );
//     ShowArayElem(arr, sizeof(arr) / sizeof(int));

//     AddArayElem(arr, sizeof(arr) / sizeof(int),3 );
//     ShowArayElem(arr, sizeof(arr) / sizeof(int));
    
//     return 0;
// }


#include <stdio.h>

int main(void)
{
    int arr5[5][5]={0,};
    int i, j;
    int num=1;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            arr5[i][j] += num;
            printf("%-2d ", arr5[i][j]);
            num++;
        }
        printf("\n");
    }
    return 0;
}
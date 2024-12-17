#include <stdio.h>

int main(void)
{
    int i, j;
    int n;
    int number=1;

    printf("배열의 크기를 정할 숫자 n을 입력해주세요. (배열 크기 : n x n) \n");
    scanf("%d", &n);

    int arr[n][n];

    for (i = 0; i < n; i++) // 배열 0으로 초기 설정
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = 0;
            printf("%-2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    i = 0;
    j = 0;

    for (i = 0; i <= n-1; i++)
    {
        if (i == 0 && j == 0)
        {
            for (j = 0; j < n; j++)
            {
                arr[i][j] += number;
                number++;
                printf("%-2d ", arr[i][j]);
            }
            printf("\n");
            continue;
        }
        else if (i == 1 && j == n)
        {
            for (j = 1; j < n; j++)
            {
                arr[j][n-i] += number;
                number++;
                printf("%-2d ", arr[i][j-1]);
            }
            printf("\n");
            continue;
        }
        else if (i == n && j == n)
        {
            for (j = 1; j < n; j++)
            {
                arr[i][j] += number;
                number++;
                printf("%-2d ", arr[i][j]);
            }
            printf("\n");
            continue;
        }
    }
    printf("\n");

    for (i = 0; i < n; i++) // 배열 0으로 초기 설정
    {
        for (j = 0; j < n; j++)
        {
            printf("%-2d ", arr[i][j]);
        }
        printf("\n");
    }
    
}
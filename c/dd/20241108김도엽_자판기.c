#include <stdio.h>

int main(void)
{
    int money;
    int num;
    int basket=0;
    while (1)
    {
        while (1)
        {
            printf("넣으실 금액을 입력해주세요 : \n");
            scanf("%d", &money);
            if (money==0)
            {
                printf("돈을 갖고오세요.\n");
                continue;
            }
            else
            {
                printf("%d원 받았습니다.\n", money);
                break;
            }
        }
        printf("[자판기 메뉴]\n");
        printf("1) 콜라 1200  2) 우주맛 콜라 1900  3) 제로콜라 1200\n");
        printf("4) 스프라이트 1100  5) 환타 900  6) 닥터페퍼 1100\n");
        printf("7) 몬스터 1800  8) 파워에이드 1900  9) 네스티 1600\n");
        printf("S) 계산하기  X) 종료하기\n");

        while (1)
        {
            scanf("%s", &num); // ASCII로 받음
            int number = num; // int값으로 수정
            switch (number)
            {
            case 49:
                basket += 1200;
                printf("1) 콜라 1200\n");
                continue;
            case 50:
                basket += 1900;
                printf("2) 콜라 1900\n");
                continue;
            case 51:
                basket += 1200;
                printf("3) 제로콜라 1200\n");
                continue;
            case 52:
                basket += 1100;
                printf("4) 스프라이트 1200\n");
                continue;
            case 53:
                basket += 900;
                printf("5) 환타 900\n");
                continue;
            case 54:
                basket += 1100;
                printf("6) 닥터페퍼 1100\n");
                continue;
            case 55:
                basket += 1800;
                printf("7) 몬스터 1800\n");
                continue;
            case 56:
                basket += 1900;
                printf("8) 파워에이드 1900\n");
                continue;
            case 57:
                basket += 1600;
                printf("9) 네스티 1600\n");
                continue;
            case 83:
                printf("계산하실 금액은 %d원 입니다.\n", basket);
                if (money >= basket)
                {
                    printf("결제가 완료되었습니다.\n");
                    printf("거스름돈은 %d원 입니다.\n", money-basket);
                    money=0;
                    basket=0;
                    break;
                }
                else
                {
                    printf("돈을 더 넣거나 다른 메뉴를 골라주세요. (부족한 금액 : %d)\n", basket-money);
                    continue;
                }
                
            case 88:
                basket = 0;
                printf("쇼핑을 마칩니다.\n");
                break;
            default:
                printf("제대로 선택하지 않아 오류가 발생했습니다. 시스템을 다시 시작합니다.\n");
                break;
            }
        break;
        }
        continue;
    }

    return 0;
}
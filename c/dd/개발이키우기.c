#include <stdio.h>
#include <stdlib.h> // 랜덤 변수 헤더 파일
#include <time.h> // 현재 시간 변수 헤더 파일
#include <unistd.h> // sleep 변수 헤더 파일

void AffScript(int today_aff, char* developet) // 애정도에 따른 대사
{
    if (today_aff > 8)
    {
        printf("%s은(는) 당신을 사랑합니다! (애정도 +%d)\n", developet, today_aff);
    }
    else if (today_aff > 6)
    {
        printf("%s은(는) 기뻐하고 있습니다! (애정도 +%d)\n", developet, today_aff);
    }
    else if (today_aff > 4)
    {
        printf("%s은(는) 아무 생각 없어 보입니다. (애정도 +%d)\n", developet, today_aff);
    }
    else if (today_aff > 2)
    {
        printf("%s은(는) 심심해 보입니다. (애정도 +%d)\n", developet, today_aff);
    }
    else
    {
        printf("%s은(는) 우울해보입니다.. (애정도 +%d)\n", developet, today_aff);
    }
}

// 0 = 빈공간, 1 = 벽, 2 = 개발이, 3 = 상한 음식, 4 = 사료, 5 = 고구마

void RoomSetting(int room[][25], int rows) // 방 배열 구조 출력
{ 
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < 25; j++)
        {
            if (room[i][j] == 0) // 빈공간
            {
                printf("⬛ ");
            }
            else if (room[i][j] == 1) // 벽
            {
                printf("⬜ ");
            }
            else if (room[i][j] == 2) // 개발이
            {
                printf("👾 ");
            }
            else if (room[i][j] == 3) // 상한 음식
            {
                printf("🍄 ");
            }
            else if (room[i][j] == 4) // 사료
            {
                printf("🍖 ");
            }
            else if (room[i][j] == 5) // 고구마
            {
                printf("🍠 ");
            }
        }
        printf("\n");
    }
}

int main(void)
{   
    int i, j;

    srand((int)time(NULL)); // 현재시간을 이용해서 랜덤 씨드 설정

    // 0. 개발이 별명 입력받기
    char developet[100]; // 개발이 이름
    printf("개발이 키우기에 오신 것을 환영합니다!\n");
    printf("개발이의 이름을 지어주세요! : \n");
    scanf("%s", developet);
    printf("개발이의 이름 : %s\n잘 키워보아요!\n", developet);
    
    // 1. 배열로 개발이 방 구현 (가로 20 x 세로 25)
    int room[20][25] = {0,};

    // 턴마다 변화하는 변수 모음

    int aff = 0; // 애정도, 0부터 시작
    int today_aff; // 오늘의 애정도, 1~10
    int day = 1; // 턴
    double weight = 10;

    // 좌표에 관련된 변수 모음
    int first_place_i = 10; // 개발이 처음 x좌표 받아주고, 현재 x좌표 갱신
    int first_place_j = 12; // 개발이 처음 x좌표 받아주고, 현재 y좌표 갱신
    int second_place_i; // 다음 x좌표 위치
    int second_place_j; // 다음 y좌표 위치
    int temp_place_i; // 벽에 들어가지 않게 판별하기 위해 임시로 x좌표값 저장
    int temp_place_j; // 벽에 들어가지 않게 판별하기 위해 임시로 y좌표값 저장
    
    // 카운트
    int eat_count = 0; // 총 먹이를 먹은 개수


    while (1) // 3. 매턴 문구 출력
    {
        int random_XorY = rand() % 2; // x 움직일지 y 움직일지 (5. 랜덤으로 좌우 상하 한칸씩 움직이기)
        
        // 먹이 배치를 위한 변수
        int feed = rand() % 3 + 3; // 3, 4, 5 중에 랜덤으로 받기
        int feed_i = rand() % 18 + 1; // 먹이 x좌표 위치
        int feed_j = rand() % 23 + 1; // 먹이 y좌표 위치

        // 카운트
        int whats_eat = 0; // 음식 먹은 횟수 지정 및 초기화
        int holl_in_one = 0;// 개발이 입에 사료가 직행할 경우 지정 및 초기

        int afterimage_i = 0; // 개발이 움직이기 전 x위치
        int afterimage_j = 0; // 개발이 움직이기 전 y위치

        while (1)
        {
            if (random_XorY == 0) // x 움직이는 경우
            {
                temp_place_i = first_place_i + (rand() % 2) * 2 - 1;
                afterimage_i = first_place_i;
                if (temp_place_i == 0 || temp_place_i == 19) // 벽에 들어갔는가? (4. 방 벽 내부에서만 움직이기)
                {
                    continue; // 움직이지 않고, 반복문 다시
                }
                else // 벽에 안 들어간 경우
                {
                    second_place_i = temp_place_i; // 임시값에 더해본 값을 진짜 좌표값에 반영
                    first_place_i = second_place_i; // 현재 x좌표값에 반영
                    break;
                }
            }
            else if (random_XorY == 1) // y 움직이는 경우
            {
                temp_place_j = first_place_j + (rand() % 2) * 2 - 1;
                afterimage_j = first_place_j;
                if (temp_place_j == 0 || temp_place_j == 24)
                {
                    continue;
                }
                else
                {
                    second_place_j = temp_place_j;
                    first_place_j = second_place_j;
                    break;
                }
            }
        }
        
        room[afterimage_i][afterimage_j] = 0; // 잔상에 빈공간 값 대입

        for (i = 0; i < 20; i++) // 방 세팅
        {
            for (j = 0; j < 25; j++)
            {
                if (i == 0 || j == 0 || i == 19 || j == 24) // 벽 설정
                {
                    room[i][j] = 1; // 1 = 벽
                }
                else if (first_place_i == i && first_place_j == j) // 받아온 xy좌표를 개발이에게 부여, 개발이 설정
                {
                    // 8. 개발이가 돌아다니다가 먹이와 같은 위치면 먹이 먹기

                    if (room[i][j] == 3) // 3. 상한 음식이 있는 곳인가?
                    {
                        // 9. 먹이의 종류에 따라 몸무게 늘리기
                        weight -= 1; // 몸무게 늘리고
                        room[i][j] = 2; // 개발이로 덮어씌우기
                        whats_eat = 3; // feed값과 동일하게 +3
                    }
                    else if (room[i][j] == 4) // 4. 사료가 있는 곳인가?
                    {
                        weight += 1;
                        room[i][j] = 2;
                        whats_eat = 4; // feed값과 동일하게 +4
                    }
                    else if (room[i][j] == 5) // 5. 고구마가 있는 곳인가?
                    {
                        weight += 3;
                        room[i][j] = 2;
                        whats_eat = 5; // feed값과 동일하게 +5
                    }
                    else // 아무것도 없는 곳
                    {
                        room[i][j] = 2; // 2 = 개발이
                    }

                    // 낮은 확률이지만, 개발이가 이동한 곳에 먹이가 바로 생겼을 때
                    if (first_place_i == feed_i && first_place_j == feed_j)
                    {
                        holl_in_one = feed;
                    }
                    
                }
                else if (feed_i == i && feed_j == j) // //7. 매턴 방안 랜덤한 위치에 먹이 넣기
                {
                    if (room[i][j] == 0)
                    {
                        room[i][j] = feed; // 먹이칸 값 = 3, 4, 5중에 하나로 변경
                    }
                    else
                    {
                        // 먹이 칸을 새롭게 설정하고, 빈공간일 경우 넣어주고 아닌 경우 다시 새롭게 설정
                        while (1)
                        {
                            int new_feed_i = rand() % 18 + 1;
                            int new_feed_j = rand() % 23 + 1;
                            if (room[new_feed_i][new_feed_j] == 0)
                            {
                                room[new_feed_i][new_feed_j] = feed;
                                break;
                            }
                            else if (room[new_feed_i][new_feed_j] == 2) // 만약 개발이랑 만났다면?
                            {
                                if (first_place_i == new_feed_i && first_place_j == new_feed_j) // 개발이의 잔상인지 아닌지 확인해본다
                                {
                                    continue; // 본체라면 값 다시 뽑기
                                }
                                else // 잔상이라면 채워주기
                                {
                                    room[new_feed_i][new_feed_j] = feed;
                                    break;
                                }
                            }
                            else // 3, 4, 5일 경우
                            {
                                continue;
                            }
                        }
                    }
                }
                else // 필요없을줄 알았으나, 개발이 증식을 막기 위해 필요
                {
                    if (room[i][j] == 2)
                    {
                        room[i][j] = 0; // 이전 개발이 위치(잔상) 초기화 (단, 여기를 오지 않으면 잔상이 계속 남아있어 2개씩 출력될 때도 있음)
                    }
                }
            }
            printf("\n");
        }
        
        printf("%d번째 날\n", day);
        RoomSetting(room, sizeof(room) / sizeof(room[0])); // 개발이가 있는 방 출력해주는 함수
        
        if (whats_eat == 3 || holl_in_one == 3)
        {
            if (holl_in_one > 0)
            {
                weight -= 1;
                printf("상한 음식이 %s 머리 위로 떨어졌습니다! 자동 섭취됩니다. 현재 몸무게 : %0.1lf\n", developet, weight);
            }
            else
            {
                printf("%s이(가) 상한 음식을 먹었습니다. 현재 몸무게 : %0.1lf\n", developet, weight);
            }
            eat_count++;
            
            // 10. 상한 음식 먹고 10% 확률로 사망, 게임종료
            int food_poisoning = rand() % 100;
            if (food_poisoning == 0) // 0 ~ 99중에서 0이 걸렸을 때 (=1%)
            {
                printf("이럴수가! %s이(가) 식중독에 걸려 사망했습니다..\n", developet);
                break;
            }
        }
        else if (whats_eat == 4 || holl_in_one == 4)
        {
            if (holl_in_one > 0)
            {
                weight += 1;
                printf("사료가 %s 머리 위로 떨어졌습니다! 자동 섭취됩니다. 현재 몸무게 : %0.1lf\n", developet, weight);
            }
            else
            {
                printf("%s이(가) 사료를 먹었습니다. 현재 몸무게 : %0.1lf\n", developet, weight);
            }
            eat_count++;
        }
        else if (whats_eat == 5 || holl_in_one == 5)
        {
            if (holl_in_one > 0)
            {
                weight += 3;
                printf("고구마가 %s 머리 위로 떨어졌습니다! 자동 섭취됩니다. 현재 몸무게 : %0.1lf\n", developet, weight);
            }
            else
            {
                printf("%s이(가) 고구마를 먹었습니다. 현재 몸무게 : %0.1lf\n", developet, weight);
            }
            eat_count++;
        }
        else
        {
            printf("%s이(가) 아무것도 먹지 못했습니다. 현재 몸무게 : %0.1lf\n", developet, weight);
        }

        // 10. 몸무게 0kg가 되어 사망
        if (weight <= 0) // 
        {
            printf("%s이(가) 오랫동안 아무것도 먹지 못해 굶어죽었습니다....\n", developet);
        }
        
        today_aff = rand() % 10 + 1;
        aff += today_aff; // 6. 애정도 1~10 증가
        AffScript(today_aff, developet);
        printf("현재 애정도는 %d입니다.\n", aff);

        // 11. 개발이 100kg 달성, 게임종료
        if (weight >= 100)
        {
            // 12. 미션 성공 그림, 문구, 애정도, 총 먹이를 먹은 개수, 턴 수 출력
            printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡯⣖⡷⡝⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⡛⡿⢛⣻⣿⣿⣿⣿⣿⣿⣿\n");
            printf("⣿⣿⣿⣿⣿⣿⣟⣞⣮⣻⣯⡳⢟⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣎⠪⡢⠣⣱⣿⣿⣿⣿⣿⣿⣿\n");
            printf("⣿⣿⣿⣿⠿⣿⣧⣳⡳⢹⣿⣧⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
            printf("⣿⣿⣿⠁⡆⢸⣿⣿⣿⣹⣿⢯⣿⣿⣿⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣑⣨⠿⣿⣿⣿⣿⣿⣿⣿\n");
            printf("⣿⡟⣉⣸⣥⠙⣿⣿⣿⣝⢰⠌⣯⢏⡛⢿⢿⣟⢰⠆⠿⠋⡌⢽⣻⣻⣻⣿⡿⠟⣽⢧⣣⣹⣿⠋⡉⢿⣿⣿\n");
            printf("⣿⣷⣤⢀⡼⠲⡌⠛⢛⣃⣘⣠⠙⠔⡇⢸⡁⠶⠚⠚⢛⠠⣧⣘⠊⡴⢸⣿⠀⡆⠈⢭⣭⣉⢻⢰⡇⣾⣿⣿\n");
            printf("⣿⡿⠓⣈⣀⣡⡤⠠⣭⡅⣠⣄⠺⠀⣇⣬⠌⢁⡞⣦⠙⠘⢃⡔⢰⠇⠾⠿⢨⡇⠆⣾⢠⣴⣾⢸⡧⠤⠄⢹\n");
            printf("⣿⣷⣌⠍⢀⣸⣀⢺⣿⠀⣏⣸⠃⠀⡇⢰⣶⢦⠙⠁⣯⣄⡦⢱⣌⣙⡛⣓⠘⠃⣇⠓⠶⠦⠆⢸⠇⣶⣶⣿\n");
            printf("⣿⣿⣧⣘⣉⣅⢸⠀⡿⠷⠬⠥⢾⢦⢰⣍⡖⢫⣽⡄⠳⠼⢃⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣿⣦⣶⣿⣿⣿\n");
            printf("⣿⣿⣿⣿⣿⣿⣶⣶⣽⣨⡫⣚⣌⣯⣧⣧⣾⣿⣿⣿⣷⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
            printf("축하합니다! %s이(가) 무사히 100kg에 도달했습니다.\n", developet);
            printf("애정도 : %d\n", aff);
            printf("총 먹이를 먹은 개수 : %d\n", eat_count);
            printf("턴 수 : %d\n", day);
            break;
        }

        day++; // 턴 수 추가
        usleep(1000000);
    }

    return 0;
}
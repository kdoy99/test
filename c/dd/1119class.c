// 구조체 만들기

// #include <stdio.h>
// #include <math.h>

// struct point
// {
//     int xpos;
//     int ypos;
// };

// int main(void)
// {
//     struct point pos1, pos2;
//     double distance;

//     fputs("point1 pos: ", stdout);
//     scanf("%d %d", &pos1.xpos, &pos1.ypos);

//     fputs("point2 pos: ", stdout);
//     scanf("%d %d", &pos2.xpos, &pos2.ypos);

//     distance=sqrt((double)((pos1.xpos-pos2.xpos)*(pos1.xpos-pos2.xpos)+
//             (pos1.ypos-pos2.ypos)*(pos1.ypos-pos2.ypos)));

//     printf("두 점의 거리는 %g 입니다. \n", distance);
//     return 0;
// }


// 구조체 만들기 2, 배열

// #include <stdio.h>
// #include <string.h>

// struct person
// {
//     char name[20];
//     char phoneNum[20];
//     int age;
// };

// int main(void)
// {
//     struct person man1, man2;
//     strcpy(man1.name, "안성준");
//     strcpy(man1.phoneNum, "010-1122-3344");
//     man1.age=23;
    
//     printf("이름 입력: "); scanf("%s", man2.name);
//     printf("번호 입력: "); scanf("%s", man2.phoneNum);
//     printf("나이 입력: "); scanf("%d", &(man2.age));

//     printf("이름: %s \n", man1.name);
//     printf("번호: %s \n", man1.phoneNum);
//     printf("나이: %d \n", man1.age);

//     printf("이름: %s \n", man2.name);
//     printf("번호: %s \n", man2.phoneNum);
//     printf("나이: %d \n", man2.age);

//     return 0;
// }


// 구조체 배열

// #include <stdio.h>

// struct point
// {
//     int xpos;
//     int ypos;
// };

// int main(void)
// {
//     struct point arr[3];
//     int i;

//     for (i = 0; i < 3; i++)
//     {
//         printf("점의 좌표 입력: ");
//         scanf("%d %d", &arr[i].xpos, &arr[i].ypos);
//     }
    
//     for (i = 0; i < 3; i++)
//     {
//         printf("[%d, %d]", arr[i].xpos, arr[i].ypos);

//     }
//     return 0;    
// }


// 구조체 포인터 활용

// #include <stdio.h>

// struct point
// {
//     int xpos;
//     int ypos;
// };

// int main(void)
// {
//     struct point pos1={1,2};
//     struct point pos2={100,200};
//     struct point * pptr=&pos1;
    
//     (*pptr).xpos += 4;
//     (*pptr).ypos += 5;
//     printf("[%d, %d] \n", pptr->xpos, pptr->ypos);

//     pptr=&pos2;
//     pptr -> xpos += 1; // 구조체의 주소에 접근 : -> 사용
//     pptr -> ypos += 2;
//     printf("[%d, %d] \n", (*pptr).xpos, (*pptr).ypos);
//     return 0;
// }


// 오류뜸;

// # include <stdio.h>

// struct point
// {
//     int xpos;
//     int ypos;
// };

// struct cirlcle
// {
//     double radius;
//     struct point * center;
// };

// int main(void)
// {
//     struct point cen = {2, 7};
//     double rad=5.5;

//     struct circle ring={rad, &cen};
//     printf("원의 반지름: %g \n", ring.radius);
//     printf("원의 중심 [%d, %d] \n", (ring.center)->xpos, (ring.center)->ypos);
//     return 0;
// }


// 포인터 연결 3

// #include <stdio.h>

// struct point
// {
//     int xpos;
//     int ypos;
//     struct point * ptr;
// };

// int main(void)
// {
//     struct point pos1 = {1, 1};
//     struct point pos2 = {2, 2};
//     struct point pos3 = {3, 3};

//     pos1.ptr = &pos2;
//     pos2.ptr = &pos3;
//     pos3.ptr = &pos1;

//     printf("점의 연결관계... \n");
//     printf("[%d, %d]와(과) [%d, %d] 연결 \n",
//         pos1.xpos, pos1.ypos, pos1.ptr->xpos, pos1.ptr->ypos);
//     printf("[%d, %d]와(과) [%d, %d] 연결 \n",
//         pos2.xpos, pos2.ypos, pos2.ptr->xpos, pos2.ptr->ypos);
//     printf("[%d, %d]와(과) [%d, %d] 연결 \n",
//         pos3.xpos, pos3.ypos, pos3.ptr->xpos, pos3.ptr->ypos);
    
//     return 0;
// }


// typedef 쓰기전

// #include <stdio.h>

// struct point
// {
//     int xpos;
//     int ypos;
// };

// struct person
// {
//     char name[20];
//     char phoneNum[20];
//     int age;
// };


// int main(void)
// {
//     struct point pos = {10, 20};
//     struct person man = {"이승기", "010-1212-0001", 21};

//     printf("%p %p \n", &pos, &pos.xpos);
//     printf("%p %p \n", &man, &man.name);

//     return 0;
// }


// typedef 쓴 후

// #include <stdio.h>

// struct point
// {
//     int xpos;
//     int ypos;
// };

// typedef struct point Point;

// typedef struct person
// {
//     char name[20];
//     char phoneNum[20];
//     int age;
// } Person;

// int main(void)
// {
//     Point pos = {10, 20};
//     Person man = {"이승기", "010-1212-0001", 21};

//     printf("%d %d \n", pos.xpos, pos.ypos);
//     printf("%s %s %d \n", man.name, man.phoneNum, man.age);

//     return 0;
// }


// 구조체 멤버인 배열 복사

// #include <stdio.h>

// typedef struct point
// {
//     int xpos;
//     int ypos;
// } Point;

// void ShowPosition(Point pos)
// {
//     printf("[%d, %d] \n", pos.xpos, pos.ypos);
// }

// Point GetCurrentPosition(void)
// {
//     Point cen;
//     printf("Input current pos: ");
//     scanf("%d %d", &cen.xpos, &cen.ypos);
//     return cen;
// }

// int main(void)
// {
//     Point curPos=GetCurrentPosition();
//     ShowPosition(curPos);
//     return 0;
// }


// 구조체 복사해서 함수에 집어넣기

// #include <stdio.h>

// typedef struct person
// {
//     char name[20];
//     char phoneNum[20];
//     int age;
// } Person;

// void ShowPersonInfo(Person man)
// {
//     printf("name: %s \n", man.name);
//     printf("phone: %s \n", man.phoneNum);
//     printf("age: %d \n", man.age);
// }

// Person ReadPersonInfo(void)
// {
//     Person man2;
//     printf("name? "); scanf("%s", man2.name);
//     printf("phone? "); scanf("%s", man2.phoneNum);
//     printf("age? "); scanf("%d", &man2.age);
//     return man2;
// }

// int main(void)
// {
//     Person man1=ReadPersonInfo();
//     ShowPersonInfo(man1);
//     return 0;
// }


// 원점 대칭 이동 및 스왑

// #include <stdio.h>

// typedef struct point
// {
//     int xpos;
//     int ypos;
// } Point;

// void OrgSymTrans(Point * ptr)
// {
//     ptr->xpos = (ptr->xpos) * -1;
//     ptr->ypos = (ptr->ypos) * -1;
// }

// void ShowPosition(Point pos)
// {
//     printf("[%d, %d] \n", pos.xpos, pos.ypos);
// }

// void SwapPoint(Point * ptr1, Point * ptr2)
// {
//     Point temp = *ptr1;
//     *ptr1 = *ptr2;
//     *ptr2 = temp;
// }

// int main(void)
// {
//     Point pos1 = {2, 4};
//     Point pos2 = {5, 7};

//     SwapPoint(&pos1, &pos2);
//     OrgSymTrans(&pos1);
//     ShowPosition(pos1);
//     OrgSymTrans(&pos2);
//     ShowPosition(pos2);
//     return 0;
// }


// 써클 안에 포인트

// #include <stdio.h>

// typedef struct point
// {
//     int xpos;
//     int ypos;
// } Point;

// typedef struct circle
// {
//     Point cen;
//     double rad;
// } Circle;

// void ShowCircleInfo(Circle * cptr)
// {
//     printf("[%d, %d] \n", (cptr->cen).xpos, (cptr->cen).ypos);
//     printf("radius: %g \n\n", cptr->rad);
// }

// int main(void)
// {
//     Circle c1 = {{1, 2}, 3.5};
//     Circle c2 = {2, 4, 3.9};
//     ShowCircleInfo(&c1);
//     ShowCircleInfo(&c2);
//     return 0;
// }


// 직사각형 만들기

// #include <stdio.h>

// typedef struct point
// {
//     int xpos;
//     int ypos;
// } Point;

// typedef struct rectangle
// {
//     Point lr; // 왼위
//     Point rb; // 오른아래
// } Rectangle;

// void ShowRecArea(Rectangle rec)
// {
//     printf("넓이: %d \n",
//         rec.rb.xpos-rec.lr.xpos) * (rec.rb.ypos-rec.lr.ypos);
// }

// void ShowRecPos(Rectangle rec)
// {

// }

// int main(void)
// {
//     Rectangle rec1={{1, 1}, {4, 4}};
//     Rectangle rec2={{0, 0}, {7, 5}};
//     ShowRecArea(rec1);
//     ShowRecArea(rec2);

//     return 0;
// }


// 열거형 enum

// #include <stdio.h>

// typedef enum syllable
// {
//     Do=1, Re=2, Mi=3, Fa=4, So=5, La=6, Ti=7
// } Syllable;

// void Sound(Syllable sy)
// {
//     switch(sy)
//     {
//     case Do:
//         puts("도는 하얀 도라지 🤪"); return;
//     case Re:
//         puts("레는 둥근 레코드 😂"); return;
//     case Mi:
//         puts("미는 파란 미나리 😉"); return;
//     case Fa:
//         puts("파는 예쁜 파랑새 😀"); return;
//     case So:
//         puts("솔은 작은 솔방울 😆"); return;
//     case La:
//         puts("라는 라디오고요~ 🤣"); return;
//     case Ti:
//         puts("시는 졸졸 시냇물 🫠"); return;
//     }
//     puts("다 함께 부르세~ 짠");
// }

// int main(void)
// {
//     Syllable tone;
//     for(tone=Do; tone<=Ti; tone+=1)
//         Sound(tone);
//     return 0;
// }


// 복습문제 3

#include <stdio.h>

typedef struct month
{
    char name[10];
    char init[4];
    int days;
    int titlenum;
} Month;

Month TotalDays(Month months[], int a)
{
    int i;
    for (i = 0; i < a; i++)
    {
        Month total += months[i].days;
    }
    return total;
}

// void TotalResult(int a, Month what)
// {
//     int i;
//     int total=0;

//     for (i = 0; i < a; i++)
//     {
//         total += what.days;
//     }
    
//     printf("%d월까지 총 날짜수는 %d일 입니다. \n", a, total);
// }


int main(void)
{
    Month months[12] =
    {
    {"Jenuary", "jen", 31, 1},{"February", "feb", 28, 2},
    {"March", "mar", 31, 3},{"April", "apr", 30, 4},
    {"May", "may", 31, 5},{"June", "jun", 30, 6},
    {"July", "jul", 31, 7},{"August", "aug", 31, 8},
    {"September", "sep", 30, 9},{"October", "oct", 31, 10},
    {"Novbember", "nov", 30, 11},{"December", "dec", 31, 12}
    };
    
    int a;
    printf("원하는 달의 수를 입력해주세요: \n");
    scanf("%d", &a);
    total_result=TotalDays(months, a);
    printf("%d월까지의 총 일수는 %d일 입니다. \n", months[a-1].titlenum, total_result);
    return 0;
}
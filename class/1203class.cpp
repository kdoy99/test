// // structur.cpp

// #include <iostream>
// struct inflatable
// {
//     char name[20];
//     float volume;
//     double price;
// };

// int main()
// {
//     using namespace std;
//     inflatable guest =
//     {
//         "Glorious Gloria",
//         1.88,
//         29.99
//     };

//     inflatable pal =
//     {
//         "Audacious Arthur",
//         3.12,
//         32.99
//     };

//     cout << "지금 판매하고 있는 모형풍선은\n" << guest.name;
//     cout << "와 " << pal.name << "입니다.\n";

//     cout << "두 제품을 $";
//     cout << guest.price + pal.price << "에 드리겠습니다!\n";
//     return 0;

// }


// // arrstruc.cpp

// #include <iostream>
// struct inflatable
// {
//     char name[20];
//     float volume;
//     double price;
// };
// int main()
// {
//     using namespace std;
//     inflatable quests[2] =
//     {
//         {"Bambi", 0.5, 21.99},
//         {"Godzilla", 2000, 565.99}
//     };

//     cout << quests[0].name << "와 " << quests[1].name
//          << "의 부피를 합하면\n"
//          << quests[0].volume + quests[1].volume
//          << " 세제곱피트입니다. \n";
//     return 0;
// }


// // use_new.cpp

// #include <iostream>
// int main()
// {
//     using namespace std;
//     int nights = 1001;
//     int * pt = new int;
//     *pt = 1001;

//     cout << "nights의 값 = ";
//     cout << nights << ": 메모리 위치 " << &nights << endl;
//     cout << "int 형";
//     cout << "값 = " << *pt << ": 메모리 위치 = " << pt << endl;

//     double * pd = new double;
//     *pd = 10000001.0;

//     cout << "double 형";
//     cout << "값 = " << *pd << ": 메모리 위치 = " << pd << endl;
//     cout << "포인터 pd의 메모리 위치: " << &pd << endl;
//     cout << "pt의 크기 = " << sizeof(pt);
//     cout << ": *pt의 크기 = " << sizeof(*pt) << endl;
//     cout << "pd의 크기 = " << sizeof(pd);
//     cout << ": *pd의 크기 = " << sizeof(*pd) << endl;
//     return 0;

// }


// // ptrstr.cpp

// #include <iostream>
// #include <cstring>
// int main()
// {
//     using namespace std;
//     char animal[20] = "bear";
//     const char * bird = "wren";
//     char * ps;

//     cout << animal << " and ";
//     cout << bird << "\n";

//     cout << "동물의 종류를 입력하십시오: ";
//     cin >> animal;

//     ps = animal;
//     cout << ps << "s!\n";
//     cout << "strcpy() 사용 전:\n";
//     cout << (int *) animal << ": " << animal << endl;
//     cout << (int *) ps << ": " << ps << endl;

//     ps = new char[strlen(animal) + 1];
//     strcpy(ps, animal);
//     cout << "strcpy() 사용 후:\n";
//     cout << (int *) animal << ": " << animal << endl;
//     cout << (int *) ps << ": " << ps << endl;
//     delete [] ps;
//     return 0;    
// }


// // newstrct.cpp

// #include <iostream>
// struct inflatable
// {
//     char name[20];
//     float volume;
//     double price;
// };
// int main()
// {
//     using namespace std;
//     inflatable * ps = new inflatable;
//     cout << "모형풍선의 이름을 입력하십시오: ";
//     cin.get(ps->name, 20);
//     cout << "부피를 세제곱 피트 단위로 입력하십시오: ";
//     cin >> (*ps).volume;
//     cout << "가격을 달러 단위로 입력하십시오: $";
//     cin >> ps->price;
//     cout << "이름: " << (*ps).name << endl;
//     cout << "부피: " << ps->volume << " cubic feet\n";
//     cout << "가격: $" << ps->price << endl;
//     delete ps;
//     return 0;
// }


//

#include <iostream>
#include <string>
int main()
{
    using namespace std;
    int N=0, M=0;
    cin >> N >> M;
    int** arr = new int * [N];
    for (int i = 0; i < M; i++)
    {
        arr[i] = new int[M];
        cout << arr[i] << endl;
    }
    
    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
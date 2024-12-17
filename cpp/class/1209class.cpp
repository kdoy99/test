// // 오버로딩
// #include <iostream>

// void MyFunc(void)
// {
//     std::cout << "MyFunc(void) called" << std::endl;
// }

// void MyFunc(char c)
// {
//     std::cout << "MyFunc(char c) called" << std::endl;
// }

// void MyFunc(int a, int b)
// {
//     std::cout << "MyFunc(int a, int b) called" << std::endl;
// }

// int main(void)
// {
//     MyFunc();
//     MyFunc('A');
//     MyFunc(12, 13);
//     return 0;
// }



// #include <iostream>

// void swap(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a =  *b;
//     *b = temp;
// }

// void swap(char *a, char *b)
// {
//     char temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void swap(double *a, double *b)
// {
//     double temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }


// int main(void)
// {
//     using namespace std;
//     int num1=20, num2=30;
//     swap(&num1, &num2);
//     cout << num1 << ' ' << num2 << endl;

//     char ch1 = 'A', ch2 = 'Z';
//     swap(&ch1, &ch2);
//     cout << ch1 << ' ' << ch2 << endl;

//     double dbl1 = 1.111, dbl2 = 5.555;
//     swap(&dbl1, &dbl2);
//     cout << dbl1 << ' ' << dbl2 << endl;
//     return 0;
// }


// // 매개변수 디폴트값
// #include <iostream>

// int Adder(int num1 = 1, int num2 = 2)
// {
//     return num1 + num2;
// }

// int main(void)
// {
//     using namespace std;

//     cout<<Adder()<<endl;
//     cout<<Adder(5)<<endl;
//     cout<<Adder(3,5)<<endl;
//     return 0;
// }


// #include <iostream>

// namespace BestComImp1
// {
//     void SimpleFunc(void);
// }
// namespace ProgComImp1
// {
//     void SimpleFunc(void);
// }

// int main(void)
// {
//     BestComImp1::SimpleFunc();
//     ProgComImp1::SimpleFunc();
//     return 0;
// }

// void BestComImp1::SimpleFunc(void)
// {
//     std::cout << "BestCom이 정의한 함수" << std::endl;
// }

// void ProgComImp1::SimpleFunc(void)
// {
//     std::cout << "ProgCom이 정의한 함수" << std::endl;
// }


/*
* Banking System Ver 0.1
* 작성자: 윤성우
* 내 용: OOP 단계별 프로젝트의 기본 틀 구성
*/

// #include <iostream>
// #include <cstring>

// using namespace std;
// const int NAME_LEN = 20;

// void ShoeMenu(void);
// void MakeAccount(void);
// void DepositMoney(void);
// void WithdrawMoney(void);
// void ShowAllAccInfo(void);

// enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

// typedef struct
// {
//     int accID;
//     int balance;
//     char cusName[NAME_LEN];
// } Account;

// Account accArr[100];
// int accNum = 0;

// int main(void)
// {
//     int choice;

//     while (1)
//     {
//         ShowMenu();
//         cout << "선택: ";
//         cin >> choice;
//         cout << endl;

//         switch (choice)
//         {
//         case MAKE:
//             MakeAccount();
//             break;
//         case DEPOSIT:
//             DepositMoney();
//             break;
//         case WITHDRAW:
//             WithdrawMoney();
//             break;
//         case INQUIRE:
//             ShowAllAccInfo();
//             break;
//         case EXIT:
//             return 0;
//         default:
//             cout << "Illegal selection.." << endl;
//         }
//     }
//     return 0;
// }

// void ShowMenu(void)
// {
//     cout << "-----Menu------" << endl;
//     cout << "1. 계좌개설" << endl;
//     cout << "2. 입 금" << endl;
//     cout << "3. 출 금" << endl;
//     cout << "4. 계좌정보 전체 출력" << endl;
//     cout << "5. 프로그램 출력" << endl;
// }

// void MakeAccount(void)
// {
//     int id;
//     char name[NAME_LEN];
//     int balance;

//     cout << "[계좌개설]" << endl;
//     cout << "계좌ID: "; cin >> id;
// }


// 레퍼런스

// #include <iostream>
// using namespace std;

// int main(void)
// {
//     int arr[3] = {1, 3, 5};
//     int &ref1 = arr[0];
//     int &ref2 =  arr[1];
//     int &ref3 = arr[2];

//     cout << ref1 << endl;
//     cout << ref2 << endl;
//     cout << ref3 << endl;
//     return 0;
// }


// 포인터 레퍼런스

// #include <iostream>
// using namespace std;

// int main(void)
// {
//     int num = 12;
//     int *ptr = &num;
//     int **dptr = &ptr;
    
//     int &ref = num;
//     int *(&pref) = ptr;
//     int **(&dpref) = dptr;

//     cout << ref << endl;
//     cout << *pref << endl;
//     cout << **dpref << endl;
//     return 0;
// }



// int& RefRetFuncOne (int &ref)
// {
//     ref++;
//     return ref;
// }

// int main(void)
// {
//     int num1 = 1;
//     int &num2 = RefRetFuncOne(num1);

//     num1++;
//     num2++;
//     cout << "num1: " << num1 << endl;
//     cout << "num2: " << num2 << endl;
//     return 0;
// }


// 동적할당

#include <iostream>
#include <cstring>

char * MakeStrAdr(int len)
{
    // char * str = (char*)malloc(sizeof(char)*len);
    char * str = new char[len];
    return str;
}

int main(void)
{
    char * str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    // free(str);
    delete []str;
    return 0;
}


// 구조체

// #include <iostream>
// using namespace std;

// ID_LEN 20
// MAX_SPD 200
// FUEL_STEP 2
// ACC_STEP 10
// BRK_STEP 10

// struct Car
// {
//     char gamerID[ID_LEN];
//     int fuelGauge;
//     int curSpeed;

//     void ShowCarState()
//     {
//         cout << "소유자ID: " << gamerID << endl;
//         cout << "연료량: " << fuelGauge << "%" << endl;
//         cout << "현재속도: " << curSpeed << "km/s" << endl;
//     }
//     void Accel()
//     {
//         if (fuelGauge <= 0)
//             return;
//         else
//             fuelGauge -= FUEL_STEP;

//         if (curSpeed+ACC_STEP>=MAX_SPD)
//         {
//             curSpeed = MAX_SPD;
//             return;
//         }
        
//         curSpeed+=ACC_STEP;        
//     }

//     void Break()
//     {
//         if(curSpeed<BRK_STEP)
//         {
//             curSpeed=0;
//             return;
//         }
        
//         curSpeed-=BRK_STEP;
//     }
// };

// int main(void)
// {
//     Car run99 = {"run99", 100, 0};
//     run99.Accel();
//     run99.Accel();
//     run99.ShowCarState();
//     run99.Break();
//     run99.ShowCarState();

//     Car sped77={"sped77", 100, 0};
//     sped77.Accel();
//     sped77.Break();
//     sped77.ShowCarState();
//     return 0;
// }

//

// #include <iostream>
// #include <cstring>

// using namespace std;

// namespace CAR_CONST
// {
//     enum
//     {
//         ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
//         ACC_STEP = 10, BRK_STEP = 10
//     };
// }

// class Car
// {
// private:
//     char gamerID[CAR_CONST::ID_LEN];
//     int fuelGauge;
//     int curSpeed;
// public:
//     void InitMembers(char * ID, int fuel);
//     void ShowCarState();
//     void Accel();
//     void Break();
// };

// void Car::InitMembers(char * ID, int fuel)
// {
//     strcpy(gamerID, ID);
//     fuelGauge = fuel;
//     curSpeed = 0;
// }

// void Car::ShowCarState()
// {
//     cout << "소유자ID: " << gamerID << endl;
//     cout << "연료량: " << fuelGauge << "%" << endl;
//     cout << "현재속도: " << curSpeed << "km/s" << endl;
// }
// void Car::Accel()
// {
//     if (fuelGauge <= 0)
//         return;
//     else
//         fuelGauge -= CAR_CONST::FUEL_STEP;

//     if (curSpeed+CAR_CONST::ACC_STEP>=CAR_CONST::MAX_SPD)
//     {
//         curSpeed = CAR_CONST::MAX_SPD;
//         return;
//     }
    
//     curSpeed+=CAR_CONST::ACC_STEP;        
// }

// void Car::Break()
// {
//     if(curSpeed<CAR_CONST::BRK_STEP)
//     {
//         curSpeed=0;
//         return;
//     }
    
//     curSpeed-=CAR_CONST::BRK_STEP;
// }

// int main(void)
// {
//     Car run99;
//     run99.InitMembers("run99", 100);
//     run99.Accel();
//     run99.Accel();
//     run99.ShowCarState();
//     run99.Break();
//     run99.ShowCarState();
//     return 0;
// }


// 객체지향 이해

// #include <iostream>
// using namespace std;

// class FruitSeller
// {
//     private:
//     int APPLE_PRICE;
//     int numOfApples;
//     int myMoney;

//     public:
//     void InitMembers(int price, int num, int money)
//     {
//         APPLE_PRICE = price;
//         numOfApples = num;
//         myMoney = money;
//     }
//     int SaleApples(int money)
//     {
//         int num = money/APPLE_PRICE;
//         numOfApples -= num;
//         myMoney += money;
//         return num;
//     }
//     void ShowSalesResult()
//     {
//         cout << "남은 사과: " << numOfApples << endl;
//         cout << "판매 수익: " << myMoney << endl << endl;
//     }
// };

// class FruitBuyer
// {
//     int myMoney;
//     int numOfApples;

//     public:
//     void InitMembers(int money)
//     {
//         myMoney = money;
//         numOfApples = 0;
//     }
//     void BuyApples(FruitSeller &seller, int money)
//     {
//         numOfApples+=seller.SaleApples(money);
//         myMoney -= money;
//     }
//     void ShowBuyResult()
//     {
//         cout << "현재 잔액: " << myMoney << endl;
//         cout << "사과 개수: numOfApples" << endl <<endl;
//     }
// };

// int main(void)
// {
//     FruitSeller seller;
//     seller.InitMembers(1000, 20, 0);
//     FruitBuyer buyer;
//     buyer.InitMembers(5000);
//     buyer.BuyApples(seller, 2000);

//     cout << "과일 판매자의 현황" << endl;
//     seller.ShowSalesResult();
//     cout << "과일 구매자의 현황" << endl;
//     buyer.ShowBuyResult();
//     return 0;


// }



// 티비 만들기

#include <iostream>
#include <cstring>
#include <ctime>
#include <unistd.h>

using namespace std;


class Television
{
    private:
    string Button;
    int channel;
    int volume;
    string show;

    public:
    int TVonoff(string Button)
    {
        while (1)
        {
            if (Button == "on")
            {
                channel = rand() % 100;
                volume = 0;
                cout << channel << "번 채널을 틀어드리겠습니다.\n";
                return channel;
            }
            else if (Button == "off")
            {
                return -1;
            }
            else
            {
                cout << "오류! 잘못된 입력입니다.\n";
                return -1;
            }
        }
    }
    void TVchange(string input)
    {
        if (input == "up")
        {
            volume++;
            cout << "볼륨을 올립니다.\n";
        }
        else if (input == "down")
        {
            volume--;
            cout << "볼륨을 내립니다.\n";
        }
        else if (input == "off")
        {
            return;
        }
        else if (input >= "0" || input <= "100")
        {
            channel = stoi(input);
            cout << "채널을 변경합니다.\n";
        }
        else
        {
            cout << "올바른 입력을 해주세요!\n";
        }
    }
    void TVscreen(string input)
    {
        cout << "========================================\n";
        cout << channel << "번 채널 시청중\n";
        cout << "========================================\n";
        cout << "⠀⠀⠀⠀⣾⣿⣿⣷⣄" << channel << channel << channel << endl;
        cout << "⠀⠀⠀⢸⣿⣿⣿⣿⣿⣧⣴⣶⣶⣶⣄" << endl;
        cout << "⠀⠀⠀⣀⣿⣿⡿⠻⣿⣿⣿⣿⣿⣿⣿⡄" << endl;
        cout << "⠀⠀⠀⢇⠠⣏⡖⠒⣿⣿⣿⣿⣿⣿⣿⣧⡀" << endl;
        cout << "⠀⠀⢀⣷⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷" << endl;
        cout << "⠀⠀⢸⣿⣿⡿⢋⠁⠀⠀⠀⠀⠉⡙⢿⣿⣿⡇" << endl;
        cout << "⠀⠀⠘⣿⣿⠀⣿⠇⠀⢀⠀⠀⠘⣿⠀⣿⡿⠁" << endl;
        cout << "⠀⠀⠀⠈⠙⠷⠤⣀⣀⣐⣂⣀⣠⠤⠾⠋⠁" << endl;
        cout << "========================================\n";
        cout << "========================================\n";
        cout << "현재 볼륨: " << volume << endl;
    }
    
};



int main(void)
{
    srand(time(NULL));

    Television tv;
    string input;

    while (1)
    {
        cout << "TV를 켜시겠습니까?\n";
        cout << "on / off 입력\n";
        cout << "=====================\n";

        cin >> input;
        
        int channel = tv.TVonoff(input);
        int volume = 0;
        if (input == "on")
        {
            while (1)
            {
                tv.TVscreen(input);
                cout << "채널을 바꾸시려면 숫자 입력\n";
                cout << "소리를 조절하시려면 up, down 입력\n";
                cout << "채널을 끄시려면 off\n";

                cin >> input;
                system("clear");
                tv.TVchange(input);

                if (input == "off")
                {
                    cout << "시청중인 채널 종료\n";
                    sleep(1);
                    system("clear");
                    break;
                }
                
            }
        }
        else if (input == "off")
        {
            cout << "TV를 종료합니다.\n";
            sleep(2);
            system("clear");
            break;
        }
        else
        {
            continue;
        }
    }
}
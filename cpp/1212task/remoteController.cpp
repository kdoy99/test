#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

enum {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

enum {ON_OFF=10, ALL_OFF, UP1, DOWN1, UP2, DOWN2, MODE};

enum {TV1, TV2, AIRC1, AIRC2, AIRR, LIGHT1, LIGHT2, LIGHT3, LIGHT4, LIGHT5, WATCH1, WATCH2, FUR_COUNT = 11};

int alreadyUse[FUR_COUNT]={-3,};
string furList[FUR_COUNT]=
{
"L사 TV(거실)", "S사 TV(안방)",
"L사 에어컨(거실)", "S사 에어컨(안방)",
"L사 공기청정기(거실)",
"거실등", "안방등", "현관등", "화장실등",
"시계(거실)", "시계(안방)"
};
string list[10]={"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"}; // 리모컨 버튼별로 등록된 정보 저장
int activeNum[10]={0,}; // 활성화 된 번호 구별
int kindList[10]={-1,}; // 몇번 버튼에 등록된 가전제품이 무슨 종류인지 번호로 저장
int selectNum; // kindList와 연계

class remoteController
{
    private:
        bool onOff;
        int upDown1;
        int upDown2;
        int mode;

    public:
        void ShowRemote();
        void allOffSelect();
        virtual void onOffSelect();
        virtual void volumeUp1();
        virtual void volumeDown1();
        virtual void volumeUp2();
        virtual void volumeDown2();
        virtual void modeButton();
        void kindSet(int select);
        void registFur(int select);
        ~remoteController();
};

void remoteController::ShowRemote()
{
    cout << "=========================" << endl;
    cout << " ⛔      🔴      #️⃣" << endl;
    cout << endl;
    cout << "    🔼    ⏫" << endl;
    cout << "    🔽    ⏬" << endl;
    cout << endl;
    cout << "0️⃣   1️⃣   2️⃣   3️⃣   4️⃣" << endl;
    cout << "5️⃣   6️⃣   7️⃣   8️⃣   9️⃣" << endl;
    cout << "=========================" << endl;
    cout << "⛔ : 10, 🔴 : 11, 🔼 : 12, 🔽 : 13" << endl;
    cout << "⏫ : 14, ⏬ : 15, #️⃣  : 16" << endl;
    cout << "=========================" << endl;
}

void remoteController::onOffSelect() // ON_OFF
{
    if (onOff == true)
    {
        onOff = false;
        cout << "전원을 끕니다." << endl;
    }
    else if (onOff == false)
    {
        onOff = true;
        cout << "전원을 킵니다." << endl;
    }
}

void remoteController::allOffSelect() // ALL_OFF
{
    if (onOff == true)
    {
        cout << "모든 제품 전원 OFF!" << endl;
        onOff = false;
    }
    else
    {
        cout << "이미 모든 제품이 꺼져있습니다!!" << endl;
    }
}

void remoteController::volumeUp1()
{
    cout << "먼저 가전제품을 선택해주세요!!" << endl;
}

void remoteController::volumeDown1()
{
    cout << "먼저 가전제품을 선택해주세요!!" << endl;
}

void remoteController::volumeUp2()
{
    cout << "먼저 가전제품을 선택해주세요!!" << endl;
}

void remoteController::volumeDown2()
{
    cout << "먼저 가전제품을 선택해주세요!!" << endl;
}

void remoteController::kindSet(int select)
{
    if (select == TV1)
    {
        kindList[selectNum] = TV1;        
    }
    else if (select == TV2)
    {
        kindList[selectNum] = TV2;
    }
    else if (select == AIRC1)
    {
        kindList[selectNum] = AIRC1;
    }
    else if (select == AIRC2)
    {
        kindList[selectNum] = AIRC2;
    }
    else if (select == AIRR)
    {
        kindList[selectNum] = AIRR;
    }
    else if (select == LIGHT1)
    {
        kindList[selectNum] = LIGHT1;
    }
    else if (select == LIGHT2)
    {
        kindList[selectNum] = LIGHT2;
    }
    else if (select == LIGHT3)
    {
        kindList[selectNum] = LIGHT3;
    }
    else if (select == LIGHT4)
    {
        kindList[selectNum] = LIGHT4;
    }
    else if (select == LIGHT5)
    {
        kindList[selectNum] = LIGHT5;
    }
    else if (select == WATCH1)
    {
        kindList[selectNum] = WATCH1;
    }
    else if (select == WATCH2)
    {
        kindList[selectNum] = WATCH2;
    }
    selectNum = -1; // 초기화
}

void remoteController::registFur(int select)
{
    while (1)
    {
        cout << "==================================" << endl;
        cout << "현재 등록된 가구" << endl;
        cout << "==================================" << endl;
        for (int i = ZERO; i <= NINE; i++)
        {
            if (list[i] != "0")
            {
                cout << i << "번: " << list[i] << endl;
            }
        }        
        cout << "==================================" << endl;
        cout << "몇번째 번호에 등록하시겠습니까? : ";

        cin >> selectNum;
        system("clear");

        if (list[selectNum] == "0")
        {
            list[selectNum] = furList[select];
            cout << selectNum << "번에 가구 " << furList[select] << "를 등록하였습니다!" << endl;
            return;
        }
        else
        {
            cout << "제대로 된 번호를 입력해주세요!!" << endl;
            continue;
        }
        
    }
}

void remoteController::modeButton()
{
    int choice;
    while (1)
    {
        cout << "1. 가구 등록" << endl;
        cout << "2. 가구 등록 해제" << endl;
        cout << "3. 등록된 가구 보기" << endl;
        cout << "4. 뒤로가기" << endl;
        
        cin >> choice;
        system("clear");

        if (choice == 1)
        {
            while (1)
            {
                int select;

                cout << "==================================" << endl;
                cout << "등록 하실 가구를 선택해주십시오." << endl;
                cout << "뒤로가기 : -1" << endl;
                cout << "==================================" << endl;
                for (int i = 0; i < FUR_COUNT; i++)
                {
                    for (int j = ZERO; j <= NINE; j++)
                    {
                        if (furList[i] == list[j])
                        {
                            alreadyUse[i] = i;
                        }
                    }
                    if (alreadyUse[i] != i)
                    {
                        cout << i << "번: " << furList[i] << endl;
                    }
                }

                cin >> select;
                system("clear");

                if (select >= 0 && select < FUR_COUNT && alreadyUse[select] != select)
                {
                    cout << select << "번 가구 " << furList[select] << " 를 선택하셨습니다." << endl;
                    registFur(select);
                    kindSet(select);
                    break;
                }
                else if (select == -1)
                {
                    cout << "뒤로 돌아갑니다." << endl;
                    break;                
                }
                else
                {
                    cout << "제대로 된 번호를 선택해주세요 !!" << endl;
                    continue;
                }
            }
        }
        else if (choice == 2)
        {
            while (1)
            {
                cout << "==================================" << endl;
                cout << "등록 해제하실 가구를 선택해주십시오." << endl;
                cout << "뒤로가기 : -1" << endl;
                cout << "==================================" << endl;
                for (int i = ZERO; i <= NINE; i++)
                {
                    if (list[i] != "0")
                    {
                        cout << i << "번: " << list[i] << endl;
                    }
                }
                cin >> choice;
                system("clear");
                if (choice >= ZERO && choice <= NINE && list[choice] != "0")
                {
                    list[choice] = "0";
                    kindSet(choice);
                    cout << choice << "번 가구를 등록 해제했습니다." << endl;
                }
                else if (choice == -1)
                {
                    cout << "뒤로 돌아갑니다." << endl;
                    break;
                }
                else
                {
                    cout << "제대로 된 번호를 선택해주세요 !!" << endl;
                    continue;
                }
            }
        }
        else if (choice == 3)
        {
            cout << "==================================" << endl;
            cout << "현재 등록된 가구" << endl;
            cout << "뒤로가기 : -1" << endl;
            cout << "==================================" << endl;
            for (int i = ZERO; i <= NINE; i++)
            {
                if (list[i] != "0")
                {
                    cout << i << "번: " << list[i] << kindList[i] << endl;
                }
            }        
            cout << "==================================" << endl;
            int exit;
            cin >> exit;
            if (exit == -1)
            {
                cout << "뒤로 돌아갑니다." << endl;
                break;
            }
            else
            {
                cout << "제대로 된 번호를 선택해주세요 !!" << endl;
                continue;
            }
            
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

remoteController::~remoteController()
{
    cout << "리모컨에 저장공간이 없어 데이터가 모두 날아갑니다! T_T" << endl;
}

class Television : public remoteController
{
    private:
    int num;
    bool onOff = 0;
    int TVvolume1 = 0;
    int TVvolume2 = 0;
    int sleepTime = 0;


    public:
    // virtual
    void onOffSelect();
    void volumeUp1();
    void volumeDown1();
    void volumeUp2();
    void volumeDown2();
    void modeButton();


};

void Television::onOffSelect() // 오버라이딩
{
    if (onOff == 0)
    {
        cout << "TV를 켭니다." << endl;
        onOff = 1;
        return;
    }
    cout << "TV를 끕니다." << endl;
    onOff = 0;
}

void Television::volumeUp1() // 오버라이딩
{
    if (onOff == 0)
    {
        cout << "TV가 꺼져있습니다!!" << endl;
        return;
    }
    
    if (TVvolume1 == 100)
    {
        cout << "최대 볼륨에 도달했습니다!!" << endl;
        cout << "현재 TV 볼륨: " << TVvolume1 << endl;
    }
    else
    {
        TVvolume1++;
        cout << "TV 볼륨을 올립니다." << endl;
        cout << "현재 TV 볼륨: " << TVvolume1 << endl;
    }
    
}

void Television::volumeDown1() // 오버라이딩
{
    if (onOff == 0)
    {
        cout << "TV가 꺼져있습니다!!" << endl;
        return;
    }

    if (TVvolume1 == 0)
    {
        cout << "최소 볼륨에 도달했습니다!!" << endl;
        cout << "현재 TV 볼륨: " << TVvolume1 << endl;
    }
    else
    {
        TVvolume1--;
        cout << "TV 볼륨을 내립니다." << endl;
        cout << "현재 TV 볼륨: " << TVvolume1 << endl;
    }
}

void Television::volumeUp2() // 오버라이딩
{
    if (onOff == 0)
    {
        cout << "TV가 꺼져있습니다!!" << endl;
        return;
    }
    
    if (TVvolume2 == 100)
    {
        TVvolume2 = 0;
        cout << "TV 채널을 변경합니다." << endl;
        cout << "현재 TV 채널: " << TVvolume2 << endl;
    }
    else
    {
        TVvolume2++;
        cout << "TV 채널을 변경합니다." << endl;
        cout << "현재 TV 채널: " << TVvolume2 << endl;
    }
    
}

void Television::volumeDown2() // 오버라이딩
{
    if (onOff == 0)
    {
        cout << "TV가 꺼져있습니다!!" << endl;
        return;
    }

    if (TVvolume2 == 0)
    {
        TVvolume2 = 100;
        cout << "TV 채널을 변경합니다." << endl;
        cout << "현재 TV 볼륨: " << TVvolume2 << endl;
    }
    else
    {
        TVvolume2--;
        cout << "TV 채널을 변경합니다." << endl;
        cout << "현재 TV 볼륨: " << TVvolume2 << endl;
    }
    
}

void Television::modeButton()
{
    if (onOff == 0)
    {
        cout << "TV가 꺼져있습니다!!" << endl;
        return;
    }

    if (sleepTime == 24)
    {
        sleepTime = 1;
        cout << "취침 시간을 설정합니다." << endl;
        cout << "현재 설정된 취침 시간: " << sleepTime << "시" << endl;
    }
    else
    {
        sleepTime++;
        cout << "취침 시간을 설정합니다." << endl;
        cout << "현재 설정된 취침 시간: " << sleepTime << "시" << endl;
    }
    
}

class AirController : public remoteController
{
    private:
    int num;
    bool onOff = 0;
    int ARCtp1 = 25;
    int ARCwind2 = 0;
    int sleepTime = 0;


    public:
    // virtual
    void onOffSelect();
    void volumeUp1();
    void volumeDown1();
    void volumeUp2();
    void volumeDown2();
    void modeButton();


};

void AirController::onOffSelect()
{
    if (onOff == 0)
    {
        cout << "에어컨을 켭니다." << endl;
        onOff = 1;
        return;
    }
    cout << "에어컨을 끕니다." << endl;
    onOff = 0;
}
void AirController::volumeUp1()
{
    if (onOff == 0)
    {
        cout << "에어컨이 꺼져있습니다!!" << endl;
        return;
    }
    if (ARCtp1 == 30)
    {
        cout << "최대 온도에 도달했습니다!!" << endl;
        cout << "현재 에어컨 온도: " << ARCtp1 << endl;
    }
    else
    {
        ARCtp1++;
        cout << "에어컨 온도를 올립니다." << endl;
        cout << "현재 에어컨 온도: " << ARCtp1 << endl;
    }
}
void AirController::volumeDown1()
{
    if (onOff == 0)
    {
        cout << "에어컨이 꺼져있습니다!!" << endl;
        return;
    }
    if (ARCtp1 == 18)
    {
        cout << "최소 온도에 도달했습니다!!" << endl;
        cout << "현재 에어컨 온도: " << ARCtp1 << endl;
    }
    else
    {
        ARCtp1--;
        cout << "에어컨 온도를 내립니다." << endl;
        cout << "현재 에어컨 온도: " << ARCtp1 << endl;
    }
}
void AirController::volumeUp2()
{
    if (onOff == 0)
    {
        cout << "에어컨이 꺼져있습니다!!" << endl;
        return;
    }
    if (ARCwind2 == 5)
    {
        cout << "최대 바람세기에 도달했습니다!!" << endl;
        cout << "현재 에어컨 바람세기: " << ARCwind2 << endl;
    }
    else
    {
        ARCwind2++;
        cout << "에어컨 바람세기를 올립니다." << endl;
        cout << "현재 바람세기: " << ARCwind2 << endl;
    }
}
void AirController::volumeDown2()
{
    if (onOff == 0)
    {
        cout << "에어컨이 꺼져있습니다!!" << endl;
        return;
    }
    if (ARCwind2 == 0)
    {
        cout << "최소 바람세기에 도달했습니다!!" << endl;
        cout << "현재 에어컨 바람세기: " << ARCwind2 << endl;
    }
    else
    {
        ARCwind2--;
        cout << "에어컨 바람세기를 내립니다." << endl;
        cout << "현재 바람세기: " << ARCwind2 << endl;
    }
}
void AirController::modeButton()
{
    if (onOff == 0)
    {
        cout << "에어컨이 꺼져있습니다!!" << endl;
        return;
    }
    if (sleepTime == 24)
    {
        sleepTime = 1;
        cout << "취침 시간을 설정합니다." << endl;
        cout << "현재 설정된 취침 시간: " << sleepTime << "시" << endl;
    }
    else
    {
        sleepTime++;
        cout << "취침 시간을 설정합니다." << endl;
        cout << "현재 설정된 취침 시간: " << sleepTime << "시" << endl;
    }
    
}

class AirRefreasher : public remoteController
{
    private:
    int num;
    bool onOff = 0;
    int ARRtp1 = 0;
    int ARRwind2 = 0;
    int sleepTime = 0;


    public:
    // virtual
    void onOffSelect();
    void volumeUp1();
    void volumeDown1();
    void volumeUp2();
    void volumeDown2();
    void modeButton();


};

void AirRefreasher::onOffSelect()
{
    if (onOff == 0)
    {
        cout << "공기청정기를 켭니다." << endl;
        onOff = 1;
        return;
    }
    cout << "공기청정기를 끕니다." << endl;
    onOff = 0;
}
void AirRefreasher::volumeUp1()
{
    if (onOff == 0)
    {
        cout << "공기청정기가 꺼져있습니다!!" << endl;
        return;
    }
    if (ARRtp1 == 5)
    {
        cout << "더이상 회전할 수 없습니다!!" << endl;
        cout << "현재 공기청정기 방향: " << ARRtp1 << endl;
    }
    else
    {
        ARRtp1++;
        cout << "공기청정기를 우측으로 회전합니다." << endl;
        cout << "현재 회전 정도: " << ARRtp1 << endl;
    }
}
void AirRefreasher::volumeDown1()
{
    if (onOff == 0)
    {
        cout << "공기청정기가 꺼져있습니다!!" << endl;
        return;
    }
    if (ARRtp1 == -5)
    {
        cout << "더이상 회전할 수 없습니다!!" << endl;
        cout << "현재 공기청정기 방향: " << ARRtp1 << endl;
    }
    else
    {
        ARRtp1--;
        cout << "공기청정기를 좌측으로 회전합니다." << endl;
        cout << "현재 회전 정도: " << ARRtp1 << endl;
    }
}
void AirRefreasher::volumeUp2()
{
    if (onOff == 0)
    {
        cout << "공기청정기가 꺼져있습니다!!" << endl;
        return;
    }
    if (ARRwind2 == 5)
    {
        cout << "최대 바람세기에 도달했습니다!!" << endl;
        cout << "현재 공기청정기 바람세기: " << ARRwind2 << endl;
    }
    else
    {
        ARRwind2++;
        cout << "공기청정기 바람세기를 올립니다." << endl;
        cout << "현재 바람세기: " << ARRwind2 << endl;
    }
}
void AirRefreasher::volumeDown2()
{
    if (onOff == 0)
    {
        cout << "공기청정기가 꺼져있습니다!!" << endl;
        return;
    }
    if (ARRwind2 == 0)
    {
        cout << "최소 바람세기에 도달했습니다!!" << endl;
        cout << "현재 공기청정기 바람세기: " << ARRwind2 << endl;
    }
    else
    {
        ARRwind2--;
        cout << "공기청정기 바람세기를 내립니다." << endl;
        cout << "현재 바람세기: " << ARRwind2 << endl;
    }
}
void AirRefreasher::modeButton()
{
    if (onOff == 0)
    {
        cout << "공기청정기가 꺼져있습니다!!" << endl;
        return;
    }
    if (sleepTime == 24)
    {
        sleepTime = 1;
        cout << "취침 시간을 설정합니다." << endl;
        cout << "현재 설정된 취침 시간: " << sleepTime << "시" << endl;
    }
    else
    {
        sleepTime++;
        cout << "취침 시간을 설정합니다." << endl;
        cout << "현재 설정된 취침 시간: " << sleepTime << "시" << endl;
    }
    
}

class Light : public remoteController
{
    private:
    int num;
    bool onOff = 0;


    public:
    // virtual
    void onOffSelect();
    void volumeUp1();
    void volumeDown1();
    void volumeUp2();
    void volumeDown2();
    void modeButton();
};

void Light::onOffSelect()
{
    if (onOff == 0)
    {
        cout << "전등을 켭니다." << endl;
        onOff = 1;
        return;
    }
    cout << "전등을 끕니다." << endl;
    onOff = 0;
}
void Light::volumeUp1()
{
    cout << "올바르지 않은 접근입니다!!" << endl;
}
void Light::volumeDown1()
{
    cout << "올바르지 않은 접근입니다!!" << endl;
}
void Light::volumeUp2()
{
    cout << "올바르지 않은 접근입니다!!" << endl;
}
void Light::volumeDown2()
{
    cout << "올바르지 않은 접근입니다!!" << endl;
}
void Light::modeButton()
{
    cout << "올바르지 않은 접근입니다!!" << endl;
}

class Watch : public remoteController
{
    private:
    int num;
    bool onOff = 0;
    int hour = 0;
    int minute = 0;
    int alarmTime = 0;


    public:
    // virtual
    void onOffSelect();
    void volumeUp1();
    void volumeDown1();
    void volumeUp2();
    void volumeDown2();
    void modeButton();
};

void Watch::onOffSelect()
{
    if (onOff == 0)
    {
        cout << "시계를 켭니다." << endl;
        cout << "현재 시각: " << hour << "시 " << minute << "분" << endl;
        onOff = 1;
        return;
    }
    cout << "시계를 끕니다." << endl;
    onOff = 0;
}
void Watch::volumeUp1()
{
    if (onOff == 0)
    {
        cout << "시계가 꺼져있습니다!!" << endl;
        return;
    }
    if (hour == 24)
    {
        hour = 1;
        cout << "시침을 1 올립니다." << endl;
        cout << "현재 설정된 시침: " << hour << "시" << endl;
    }
    else
    {
        hour++;
        cout << "시침을 1 올립니다." << endl;
        cout << "현재 설정된 시침: " << hour << "시" << endl;
    }
}
void Watch::volumeDown1()
{
    if (onOff == 0)
    {
        cout << "시계가 꺼져있습니다!!" << endl;
        return;
    }
    if (hour == 0)
    {
        hour = 23;
        cout << "시침을 1 내립니다." << endl;
        cout << "현재 설정된 시침: " << hour << "시" << endl;
    }
    else
    {
        hour--;
        cout << "시침을 1 내립니다." << endl;
        cout << "현재 설정된 시침: " << hour << "시" << endl;
    }
}
void Watch::volumeUp2()
{
    if (onOff == 0)
    {
        cout << "시계가 꺼져있습니다!!" << endl;
        return;
    }
    if (minute == 24)
    {
        minute = 1;
        cout << "분침을 1 올립니다." << endl;
        cout << "현재 설정된 분침: " << minute << "분" << endl;
    }
    else
    {
        minute++;
        cout << "분침을 1 올립니다." << endl;
        cout << "현재 설정된 분침: " << minute << "분" << endl;
    }
}
void Watch::volumeDown2()
{
    if (onOff == 0)
    {
        cout << "시계가 꺼져있습니다!!" << endl;
        return;
    }
    if (minute == 0)
    {
        minute = 23;
        cout << "분침을 1 내립니다." << endl;
        cout << "현재 설정된 분침: " << minute << "분" << endl;
    }
    else
    {
        minute--;
        cout << "분침을 1 내립니다." << endl;
        cout << "현재 설정된 분침: " << minute << "분" << endl;
    }
}
void Watch::modeButton()
{
    if (onOff == 0)
    {
        cout << "시계가 꺼져있습니다!!" << endl;
        return;
    }
    if (alarmTime == 24)
    {
        alarmTime = 1;
        cout << "알람 시간을 설정합니다." << endl;
        cout << "현재 설정된 알람 시간: " << alarmTime << "시" << endl;
    }
    else
    {
        alarmTime++;
        cout << "알람 시간을 설정합니다." << endl;
        cout << "현재 설정된 알람 시간: " << alarmTime << "시" << endl;
    }

}

int main(void)
{
    int num, i;

    Television tv1;
    Television tv2;
    AirController ac1;
    AirController ac2;
    Light lt1;
    Light lt2;
    Light lt3;
    Light lt4;
    Light lt5;
    Watch wt1;
    Watch wt2;
    
    remoteController *temp = new remoteController;
    remoteController *rmc = new remoteController;
    Television *tv_1 = &tv1;
    Television *tv_2 = &tv2;
    AirController *ac_1 = &ac1;
    AirController *ac_2 = &ac2;
    AirRefreasher *ar = new AirRefreasher;
    Light *lt_1 = &lt1;
    Light *lt_2 = &lt2;
    Light *lt_3 = &lt3;
    Light *lt_4 = &lt4;
    Light *lt_5 = &lt5;
    Watch *wt_1 = &wt1;
    Watch *wt_2 = &wt2;

    temp = rmc;

    while (1)
    {
        int dupJudge = 0; // 중복 활성화 판별

        rmc->ShowRemote();
        cout << "번호 입력: ";
        cin >> num;
        system("clear");

        if (num >= ZERO && num <= NINE)
        {
            if (list[num] == "0")
            {
                cout << "아무것도 등록되어있지 않습니다!!" << endl;
                continue;
            }
            
            if (kindList[num] == TV1)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = tv_1;
                }
            }
            else if (kindList[num] == TV2)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = tv_2;
                }
            }
            else if (kindList[num] == AIRC1)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = ac_1;
                }
            }
            else if (kindList[num] == AIRC2)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = ac_2;
                }
            }
            else if (kindList[num] == AIRR)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = ar;
                }
            }
            else if (kindList[num] == LIGHT1)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = lt_1;
                }
            }
            else if (kindList[num] == LIGHT2)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = lt_2;
                }
            }
            else if (kindList[num] == LIGHT3)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = lt_3;
                }
            }
            else if (kindList[num] == LIGHT4)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = lt_4;
                }
            }
            else if (kindList[num] == LIGHT5)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = lt_5;
                }
            }
            else if (kindList[num] == WATCH1)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = wt_1;
                }
            }
            else if (kindList[num] == WATCH2)
            {
                if (activeNum[num] == 1)
                {
                    activeNum[num] = 0;
                    cout << num << "번 버튼 비활성화!" << endl;
                    rmc = temp;
                }
                else
                {
                    for (i = 0; i < 10; i++)
                    {
                        if (activeNum[i] == 1)
                        {
                            dupJudge = 1;
                            break;
                        }
                    }
                    if (dupJudge == 1)
                    {
                        cout << "다른 활성화 된 버튼을 꺼주세요!!\n" << endl;
                        continue;
                    }
                    activeNum[num] = 1;
                    cout << num << "번 버튼 활성화!" << endl;
                    cout << "현재 선택중인 가전제품: " << list[num] << endl;
                    rmc = wt_2;
                }
            }
        }
        else if (num == ON_OFF)
        {
            rmc->onOffSelect();
        }
        else if (num == ALL_OFF)
        {
            rmc->allOffSelect();
        }
        else if (num == UP1)
        {
            rmc->volumeUp1();
        }
        else if (num == DOWN1)
        {
            rmc->volumeDown1();
        }
        else if (num == UP2)
        {
            rmc->volumeUp2();
        }
        else if (num == DOWN2)
        {
            rmc->volumeDown2();
        }
        else if (num == MODE)
        {
            rmc->modeButton();
        }
        else
        {
            continue;
        }
    }
}
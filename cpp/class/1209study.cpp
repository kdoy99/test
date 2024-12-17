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
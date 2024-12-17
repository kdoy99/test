#include<iostream>
using namespace std;

class TV{
    public:
        bool on_off = 0;
        int ch;
        int vol;
    
        void power_on_off(){
            on_off = !(on_off);

            if(on_off){
                ch = 10;
                vol = 20;
            }
        }
        void channel_up(){
            ch++;
        };
        void channel_down(){
            ch--;
        }
        void volume_up(){
            vol++;
        }
        void volume_down(){
            vol--;
        }
        void print_tv_status(){
            if(on_off){
                cout << "전원 : " << on_off << endl;
                cout << "채널 : " << ch << endl;
                cout << "볼륨 : " << vol << endl;
            }
        }
        void manipulate_tv(){
            int btn;
            while(1){
                cout << "버튼 입력 : " ;
                cin >> btn;
                getchar();
                switch(btn){
                    case 1 : power_on_off(); break;
                    case 2 : channel_up(); break;
                    case 3 : channel_down(); break;
                    case 4 : volume_up(); break;
                    case 5 : volume_down(); break;
                    default : cout << "잘못된 입력.\n"; 
                }
                if(!on_off)
                    break;
                print_tv_status();
            }
        }
};


int main(){
    TV tv;
    tv.manipulate_tv();
}
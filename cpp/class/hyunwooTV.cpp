#include <iostream>
using namespace std;

class TV
{
private:
    int on_off;
    int channel;
    int channel_up;
    int channel_down;
    int volume;
    int volume_up;
    int volume_down;

public:
    void init_TV(int power, int init_channel, int init_volume)
    {
        on_off = power;         // 메인함수에서 호출할 초기 power상태 = off (0)
        channel = init_channel; // 메인함수에서 호출할 초기 channel = 1
        volume = init_volume;   // 메인함수에서 호출할 초기 volume = 0
    }
    int TV_on_off()
    {
        int input;
        cout<<"TV를 켜시겠습니까? (on = 1)"; cin>>input;
        on_off = input;
        if (input == 1)
        {
            cout<<"TV가 켜졌습니다."<<endl;
        } 
        return input;
    }
    int ch_up_func(int ch_up)
    {
        channel += ch_up;
        cout<<"현재 채널은 "<<channel<<endl;
        cout<<"채널을 "<<ch_up<<"번 올립니다"<<endl;
        cout<<"이동한 채널은 "<<channel<<"채널 입니다"<<endl<<endl;
        return channel;
    }
    int ch_down_func(int ch_down)
    {
        if (channel > 1)
        {
            channel -= ch_down;
            cout<<"현재 채널은 "<<channel<<endl;
            cout<<"채널을 "<<ch_down<<"번 내립니다"<<endl;
            cout<<"이동한 채널은 "<<channel<<"채널 입니다"<<endl<<endl;
            return channel;
        }
        else
        {
            channel = 100;
            return channel;
        }
    }
    int vol_up_func(int vol_up)
    {
        if (volume < 100)
        {
            volume += vol_up;
            cout<<"현재 볼륨은 "<<volume<<endl;
            cout<<"볼륨을 "<< vol_up <<" 올립니다"<<endl;
            cout<<"조정한 볼륨은 "<<volume<< " 입니다"<<endl<<endl;
        }
        return volume;
    }
    int vol_down_func(int vol_down)
    {
        if (volume > 1)
        {
            volume -= vol_down;
            cout<<"현재 볼륨은 "<<volume<<endl;
            cout<<"볼륨을 "<<vol_down<<" 내립니다"<<endl;
            cout<<"조정한 볼륨은 "<<volume<<" 입니다"<<endl<<endl;
        }
        return volume;
    }
    void show_cur_TV_state()
    {
        if (on_off == 1)
        {
            cout<<"현재 TV가 켜져있습니다"<<" 채널 "<<channel<<" 볼륨 "<<volume<<endl<<endl;
        }
        else
        {
            cout<<"현재 TV가 꺼져있습니다"<<endl;
        }
    }
};

int main(void)
{
    TV tv;
    tv.init_TV(0, 1, 0); // TV꺼짐, 채널1, 볼륨0
    tv.TV_on_off();
    tv.vol_up_func(5);   // 볼륨 5 증가
    tv.vol_down_func(3); // 볼륨 3 감소
    tv.ch_up_func(20);   // 채널업 20번 = 초기 채널 1 + 20 = 21채널
    tv.ch_down_func(10); // 채널다운 10번 = 현재채널 21 - 10 = 11채널
    tv.show_cur_TV_state();
    return 0;
}
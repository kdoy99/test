#include <iostream>

using namespace std;

class Tv {
private :
    bool Tv_on_off;
    
    int channel;
    int sound;
    char sound_up;
    char sound_down;
    char up_btn;
    char down_btn;
public:
    void on_tv() {
        cout<<"티비를 켭니다."<<endl;
        return ;
    } 

    void off_tv() {
        cout<<"티비를 끕니다."<<endl;
        return;
    }
    

    void up_channel() {
        
        channel++;
        cout<<"채널을 올립니다."<<endl;
        return ;
    }   
    void down_channel() {
        
        channel--;
        cout<<"채널을 내립니다."<<endl;
        return ;

        
    }  
    void up_sound() {
        
        sound++;
        cout<<"소리를 올립니다."<<endl;

        return ;
    }   

    void down_sound() {
        sound--;
        cout<<"소리를 내립니다."<<endl;

        return ;
    }   
    void print_() {
        cout<<"1 번  : 티비를 켭니다."<<endl;
        cout<<"2 번  : 채널을 올립니다.."<<endl;
        cout<<"3번  : 채널을 내립니다.."<<endl;
        cout<<"4 번  : 소리를 올립니다."<<endl;
        cout<<"5 번  : 소리를 내립니다."<<endl;
        cout<<"6 번  : 티비를 끕니다."<<endl;

    }
};

int main(void) {

    
    Tv tv_func;
    tv_func.print_();
    int num;

    
    while (1) {
        cout<< "입력 :";
        cin >> num;
        switch(num) {
            case 1 : {tv_func.on_tv();}
            case 2 : {tv_func.up_channel();}break;
            case 3 : {tv_func.down_channel();}break;
            case 4 : {tv_func.up_sound();}break;
            case 5 : {tv_func.down_sound();}break;
            case 6 : {tv_func.off_tv();}break;
        }  
        break;


    }
    return 0;
}
// // travel.cpp

// #include <iostream>
// struct travel_time
// {
//     int hours;
//     int mins;
// };
// const int Mins_per_hr = 60;

// travel_time sum(travel_time t1, travel_time t2);
// void show_time(travel_time t);

// int main()
// {
//     using namespace std;
//     travel_time day1 = {5, 45};
//     travel_time day2 = {4, 55};

//     travel_time trip = sum(day1, day2);
//     cout << "이틀간 소요시간: ";
//     show_time(trip);

//     travel_time day3 = {4, 32};
//     cout << "사흘간 소요시간: ";
//     show_time(sum(trip, day3));

//     return 0;
// }

// travel_time sum(travel_time t1, travel_time t2)
// {
//     travel_time total;

//     total.mins = (t1.mins + t2.mins) % Mins_per_hr;
//     total.hours = t1.hours + t2.hours +
//                         (t1.mins + t2.mins) / Mins_per_hr;
//     return total;
// }

// void show_time(travel_time t)
// {
//     using namespace std;
//     cout << t.hours << "시간 "
//         << t.mins << "분\n";
// }


// topfive.cpp

#include <iostream>
#include <string>

using namespace std;
const int SIZE = 5;
void display(const string sa[], int n);
int main()
{
    string list[SIZE];
    cout << "좋아하는 밤하늘의 광경을 " << SIZE << "개 입력하시오:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ": ";
        getline(cin, list[i]);
    }

    cout << "입력하신 내용은 다음과 같습니다:\n";
    display(list, SIZE);

    return 0;
}

void display(const string sa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i+1 << ": " << sa[i] << endl;
    }
    
}
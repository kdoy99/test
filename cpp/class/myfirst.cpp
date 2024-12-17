// #include <iostream>

// int main()
// {
//     using namespace std;
//     cout << "C++의 세계로 오십시오.";
//     cout << endl;
//     cout << "후회하지 않으실 겁니다!" << endl;
//     return 0;
// }


// // carrots.cpp

// #include <iostream>

// int main()
// {
//     using namespace std;
    
//     int carrots;
    
//     carrots = 25;
//     cout << "나는 당근을 ";
//     cout << carrots;
//     cout << "개 가지고 있다.";
//     cout << endl;
//     carrots = carrots - 1;
//     cout << "아삭아삭, 이제 당근은 " << carrots << "개이다." << endl;
//     return 0;
// }


// // getinfo.cpp

// #include <iostream>

// int main()
// {
//     using namespace std;
    
//     int carrots;

//     cout << "당근을 몇 개나 가지고 있니?" << endl;
//     cin >> carrots; // C++ 입력
//     cout << "여기 두 개가 더 있다. ";
//     carrots = carrots + 2;

//     cout << "이제 당근은 모두 " << carrots << "개이다." << endl;
//     return 0;


// }


// // limits.cpp

// #include <iostream>
// #include <climits>
// int main()
// {
//     using namespace std;
//     int n_int = INT_MAX;
//     short n_short = SHRT_MAX;
//     long n_long = LONG_MAX;
//     long long n_llong = LLONG_MAX;

//     cout << "int는 " << sizeof (int) << " 바이트이다." << endl;
//     cout << "short는 " << sizeof n_short << " 바이트이다." << endl;
//     cout << "long은 " << sizeof n_long << " 바이트이다." << endl << endl;
//     cout << "long long은 " << sizeof n_llong << " 바이트이다." << endl;
//     cout << endl;

//     cout << "최댓값:" << endl;
//     cout << "int: " << n_int << endl;
//     cout << "short: " << n_short << endl;
//     cout << "long: " << n_long << endl << endl;
//     cout << "long long: " << n_llong << endl << endl;
//     cout << "int의 최솟값 = " << INT_MIN << endl;
//     cout << "바이트 당 비트 수 = " << CHAR_BIT << endl;
//     return 0;
// }


// // morechar.cpp
// #include <iostream>
// int main()
// {
//     using namespace std;
//     char ch = 'M';
//     int i = ch;
//     cout << ch << "의 ASCII 코드는 " << i << "입니다." << endl;

//     cout << "이 문자 코드에 1을 더해 보겠습니다." << endl;
//     ch = ch + 1;
//     i = ch;
//     cout << ch << "의 ASCII 코드는 " << i << "입니다." << endl;

//     // cout.put() 멤버 함수를 사용하여 char형 변수 ch를 출력한다
//     cout << "cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력: ";
//     cout.put(ch);

//     // cout.put() 을 사용하여 문자 상수를 출력한다.
//     cout.put('!');

//     cout << endl << "종료" << endl;
//     return 0;
// }


// // arrayone.cpp
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int yamsp [3];
//     yams[0] = 7;
//     yams[1] = 8;
//     yams[2] = 6;

//     int yamcosts[3] = {200, 300, 50};
//     cout << "고구마 합계 = ";
//     cout << yams[0] + yams[1] + yams[2] << endl;
//     cout << yams [1] << "개가 들어 있는 포장은";
//     cout << "개당 " << yamcosts[1]
// }


// // strings.cpp

// #include <iostream>
// #include <cstring>
// int main()
// {
//     using namespace std;
//     const int Size = 15;
//     char name1[Size];
//     char name2[Size] = "C++owboy";

//     cout << "안녕하세요! 저는 " << name2;
//     cout << "입니다! 실례지만 성함이?\n";
//     cin >> name1;
//     cout << "아, " << name1 << " 씨! 당신의 이름은 ";
//     cout << strlen(name1) <<"자입니다만 \n";
//     cout << sizeof(name1) << "바이트 크기의 배열에 저장되었습니다.\n";
//     cout << "이름이 " << name1[0] << "자로 시작하는군요.\n";
//     name2[3] = '\0';
//     cout << "제 이름의 처음 세 문자는 다음과 같습니다: ";
//     cout << name2 << endl;

//     return 0;
// }


// instr1.cpp

#include <iostream>
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    // cout << "이름을 입력하십시오:\n";
    // cin >> name;
    // cout << "좋아하는 디저트를 입력하십시오:\n";
    // cin >> dessert;
    // cout << "맛있는 " << dessert;
    // cout << " 디저트를 준비하겠습니다. " << name << " 님!\n" << endl;

    cout << "이름을 입력하십시오:\n";
    cin.getline(name, ArSize);
    cout << "좋아하는 디저트를 입력하십시오:\n";
    cin.getline(dessert, ArSize);
    cout << "맛있는 " << dessert;
    cout << " 디저트를 준비하겠습니다. " << name << " 님!\n";

    cout << "이름을 입력하십시오:\n";
    cin.get(name, ArSize);
    cout << "좋아하는 디저트를 입력하십시오:\n";
    cin.get();
    cin.get(dessert, ArSize);
    cout << "맛있는 " << dessert;
    cout << " 디저트를 준비하겠습니다. " << name << " 님!\n";
    return 0;
}


// // strtype1.cpp

// #include <iostream>
// #include <string>
// int main()
// {
//     using namespace std;
//     string s1 = "penguin";
//     string s2, s3;

//     cout << "string 객체를 string 객체에 대입할 수 있다: s2 = s1\n";
//     s2 = s1;
//     cout << "s1: " << s1 << ", s2: " << s2 << endl;
//     cout << "string 객체에 C 스타일 문자열을 대입할 수 있다.\n";
//     cout << "s2 = \"buzzard\"\n";
//     s2 = "buzzard";
//     cout << "s2: " << s2 << endl;
//     cout << "string 객체들을 결합할 수 있다: s3 = s1 + s2\n";
//     s3 = s1 + s2;
//     cout << "s3: " << s3 << endl;
//     cout << "string 객체들을 추가할 수 있다.\n";
//     s1 += s2;
//     cout << "s1 += s2 --> s1 = " << s1 << endl;
//     s2 += " for a day";
//     cout << "s2 += \"for a day\" --> s2 = " << s2 << endl;

//     return 0;
// }


// // strtype4.cpp

// #include <iostream>
// #include <string>
// #include <cstring>

// int main()
// {
//     using namespace std;
//     char charr[20];
//     string str;

//     cout << "입력 이전에 charr에 있는 문자열의 길이: "
//          << strlen(charr) << endl;
//     cout << "입력 이전에 str에 있는 문자열의 길이: "
//          << str.size() << endl;
//     cout << "텍스트 한 행을 입력하시오:\n";
//     cin.getline(charr, 20);
//     cout << "입력한 텍스트: " << charr << endl;
//     cout << "또 다른 텍스트 한 행을 입력하시오:\n";
//     getline(cin, str);
//     cout << "입력한 텍스트: " << str << endl;
//     cout << "입력 이후에 charr에 있는 문자열의 길이: "
//          << strlen(charr) << endl;
//     cout << "입력 이후에 str에 있는 문자열의 길이: "
//          << str.size() << endl;

//     return 0;
// }
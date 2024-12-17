// // forstr1.cpp

// #include <iostream>
// #include <string>
// int main()
// {
//     using namespace std;
//     cout << "단어 하나를 입력하십시오: ";
//     string word;
//     cin >> word;

//     for (int i = word.size() - 1; i>=0; i--)
//         cout << word[i];
//     cout << "\n종료.\n";
//     return 0;
// }


// // compstr1.cpp

// #include <iostream>
// #include <cstring>
// int main()
// {
//     using namespace std;
//     char word[5] = "?ate";

//     for (char ch = 'a'; strcmp(word, "mate"); ch++)
//     {
//         cout << word << endl;
//         word[0] = ch;
//     }
//     cout << "루프가 끝난 후에 단어는 " << word << "입니다.\n";
//     return 0;
// }


// compstr2.cpp

#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string word = "?ate";
    for (char ch = 'a'; word != "mate"; ch++)
    {
        cout << word << endl;
        word[0] = ch;
    }
    cout << "루프가 끝난 후에 단어는 " << word << "입니다.\n";
    return 0;
}


// // waiting.cpp

// #include <iostream>
// #include <ctime>
// int main()
// {
//     using namespace std;
//     cout << "지연 시간을 초 단위로 입력하십시오: ";
//     float secs;
//     cin >> secs;
//     clock_t delay = secs * CLOCKS_PER_SEC;

//     cout << "카운트를 시작합니다.\a\n";
//     clock_t start = clock(); // 이게 머지
//     while (clock() -  start < delay)
//     {
//         cout << clock() << endl;
//         cout << start << endl;
//         cout << clock() - start << endl;
//     }

//     cout << "종료\a\n";
    
//     return 0;
// }


// // textin1.cpp

// #include <iostream>
// int main()
// {
//     using namespace std;
//     char ch;
//     int count = 0;
//     cout << "문자들을 입력하시오; 끝내려면 #을 입력하시오:\n";
//     cin >> ch;
//     while (ch != '#')
//     {
//         cout << ch;
//         ++count;
//         cin >> ch;
//     }
//     cout << endl << count << " 문자를 읽었습니다.\n";
//     return 0;
// }


// // nested.cpp

// #include <iostream>
// const int Cities = 5;
// const int Years = 4;
// int main()
// {
//     using namespace std;
//     const char * cities[Cities] = 
//     {
//         "Seoul",
//         "Jeju",
//         "Busan",
//         "Gangneung",
//         "Daegu"
//     };

//     int maxtemps[Years][Cities] =
//     {
//         {35, 32, 33, 36, 35},
//         {33, 32, 34, 35, 31},
//         {33, 34, 32, 35, 34},
//         {36, 35, 34, 37, 35}
//     };

//     cout << "2009년부터 2012년까지의 연중 최고 온도 \n\n";
//     for (int city = 0; city < Cities; ++city)
//     {
//         cout << cities[city] << ":\t";
//         for (int year = 0; year < Years; ++year)
//         {
//             cout << maxtemps[year][city] << "\t";
//         }
//         cout << endl;
//     }
//     return 0;
// }


// // switch.cpp

// #include <iostream>
// using namespace std;


// // outfile.cpp

// #include <iostream>
// #include <fstream>
// int main()
// {
//     using namespace std;

//     char automobile[50];
//     int year;
//     double a_price;
//     double d_price;

//     ofstream outFile;
//     outFile.open("carinfo.txt");

//     cout << "자동차 메이커와 차종을 입력하시오: ";
//     cin.getline(automobile, 50);
//     cout << "연식을 입력하시오: ";
//     cin >> year;
//     cout << "구입 가격을 입력하시오: ";
//     cin >> a_price;
//     d_price = 0.913 * a_price;

//     cout << fixed;
//     cout.precision(2);
//     cout.setf(ios_base::showpoint);
//     cout << "메이커와 차종: " << automobile << endl;
//     cout << "연식 " << year << endl;
//     cout << "구입 가격 $" << a_price << endl;
//     cout << "현재 가격 $" << d_price << endl;

// //     outFile << fiexd;
// //     outFile.precision(2);
// //     outFile.setf(ios_base::showpoint);
// //     outFile << "메이커와 차종:"

//     outFile.close();
//     return 0;
// }


// // sumafile.cpp

// #include <iostream>
// #include <fstream>
// #include <cstdlib>

// const int SIZE = 60;
// int main()
// {
//     using namespace std;
//     char filename[SIZE];
//     ifstream inFile;
//     cout << "데이터 파일의 이름을 입력하시오: ";
//     cin.getline(filename, SIZE);
//     inFile.open(filename);

//     if (!inFile.is_open())
//     {
//         cout << filename << "파일을 열 수 없습니다." << endl;
//         cout << "프로그램을 종료합니다.\n";
//         exit(EXIT_FAILURE);
//     }

//     double value;
//     double sum = 0.0;
//     int count = 0;

//     inFile >> value;
//     while (inFile.good())
//     {
//         ++count;
//         sum += value;
//         inFile >> value;
//     }
//     if (inFile.eof())
//     {
//         cout << "파일 끝에 도달했습니다.\n";
//     }
//     else if (inFile.fail())
//     {
//         cout << "데이터 불일치로 입력이 종료되었습니다.\n";
//     }
//     else
//     {
//         cout << "알 수 없는 이유로 입력이 종료되었습니다.\n";
//     }
//     if (count == 0)
//     {
//         cout << "데이터가 없습니다.\n";
//     }
//     else
//     {
//         cout << "읽은 항목의 개수: " << count << endl;
//         cout << "합계: " << sum << endl;
//         cout << "평균: " << sum / count << endl;
//     }
//     inFile.close();
//     return 0;
// }


// // strgback.cpp

// #include <iostream>
// char * buildstr(char c, int n);
// int main()
// {
//     using namespace std;
//     int times;
//     char ch;

//     cout << "문자 하나를 입력하십시오: ";
//     cin >> ch;
//     cout << "정수 하나를 입력하십시오: ";
//     cin >> times;
//     char *ps = buildstr(ch, times);
//     cout << ps << endl;
//     delete [] ps;
//     ps = buildstr('+', 20);
//     cout << ps << "-DONE-" << ps << endl;
//     delete [] ps;
//     return 0;
// }

// char * buildstr(char c, int n)
// {
//     char * pstr = new char[n+1];
//     pstr[n] = '\0';
//     while (n-- > 0)
//         pstr[n] = c;
//     return pstr;
// }
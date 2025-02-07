#include <string>
#include <iostream>

using namespace std;
 
int main()
{
    string str = "Bushshllshit ditishamn";
    string del = "shit";
    
    for (size_t start = 0, stop = 0; stop != string::npos; start = stop + 1)
    {
        stop = str.find(del, start);
        cout << str.substr(start, stop - start) << endl;
    }
}
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

#define COUNT 256

using namespace std;

int max_count = 0;
char* list(char* userList[]);

int main(void)
{
    char* userList[COUNT];
    char input[100];
    while (1)
    {
        cout << "입력 : ";
        cin >> input;
        if (!strcmp(input, "q") || !strcmp(input, "Q"))
        {
            break;
        }
        userList[max_count] = input;
        max_count++;
    }

    cout << list(userList) << endl;

}

char* list(char* userList[])
{
    char msg[10000];
    char* msgp[10];
    for (int i = 0; i < max_count; i++)
    {
        strcat(msg, userList[i]);
        strcat(msg, "\n");
    }
    msgp[0] = msg;
    return (char*)msgp[0];
}
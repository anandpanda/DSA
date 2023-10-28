#include <iostream>
#include <string.h>
using namespace std;

void revstr(char name[], int len)
{
    for (int i = 0; i < len / 2; i++)
        swap(name[i], name[len - 1 - i]);
}

int main()
{
    char name[] = "Anand";
    cout << "String length : " << strlen(name) << endl;
    revstr(name, strlen(name));
    cout << name;
    return 0;
}
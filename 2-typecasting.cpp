#include <iostream>
using namespace std;

int main()
{
    char a = 123456;   // char is of 8 bits = 1 byte, hence a stores the last 8 bits (or last 1 byte) of 123456 in binary, i.e 01000000 = 64
    cout << a << endl; // 64 in ascii corresponds to @

    return 0;
}
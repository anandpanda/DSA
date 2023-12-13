#include <iostream>
using namespace std;

void printbits(int num)
{
    int flag = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit = ((num >> i) & 1);
        if (bit == 1)
            flag = 1;
        if (flag == 1)
            cout << bit;
    }
    cout << endl;
}

int main()
{
    printbits(-6);
    return 0;
}
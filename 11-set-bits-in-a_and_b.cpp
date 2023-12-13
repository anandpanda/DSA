#include <iostream>
using namespace std;

// number of set bits in a&b

int countbits(int a, int b)
{
    int count = 0;
    int temp = (a & b);
    while (temp != 0)
    {
        int bit = (temp & 1);
        if (bit == 1)
            count++;
        temp = temp >> 1;
    }

    return count;
}

int main()
{
    int a, b;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;

    cout << a << " & " << b << " : " << (a & b) << endl;
    cout << "Number of set bits in " << a << " & " << b << " : " << countbits(a, b) << endl;
    return 0;
}
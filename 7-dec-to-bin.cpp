#include <iostream>
#include <math.h>
using namespace std;

// n = 5   n & 1 = 0 if n is even, 1 if odd

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

// int bit8(int)

int main()
{
     int d = 6;

     // Approach 1:
     int b1 = 0;
     int a = d;
     int f = 1;
     while (a != 0)
     {
         int rem = a % 2;
         b1 = b1 + f * rem;
         f *= 10;
         a /= 2;
     }
     cout << b1 << endl;

     // Approach 2:
     int b2 = 0;
     int b = d, i = 0;
     while (b != 0)
     {
         int bit = b & 1;
         b2 = b2 + bit * pow(10, i);
         b = b >> 1;
         i++;
     }
     cout << b2 << endl;

    // Binary of -ve  numbers:

    /*int num = -6;
    int pnum = -num;
    int k = 1, f = 1;
    int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
    while (k <= 32)
    {
        if (k == 9 || k == 17 || k == 25)
            f = 1;
        int fb = ((pnum & 1) ^ 1);
        if (k <= 8)
        {
            b1 = b1 + fb * f;
            f *= 10;
        }
        else if (k <= 16)
        {
            b2 = b2 + fb * f;
            f *= 10;
        }
        else if (k <= 24)
        {
            b3 = b3 + fb * f;
            f *= 10;
        }
        else if (k <= 32)
        {
            b4 = b4 + fb * f;
            f *= 10;
        }
        pnum = pnum >> 1;
        k++;
    }
    cout << b4 << b3 << b2 << b1 << endl;*/

    return 0;
}
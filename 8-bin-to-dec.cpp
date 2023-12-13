#include <iostream>
using namespace std;
#include <math.h>

int main()
{

    int n, dec = 0, i = 0;
    cin >> n;
    while (n != 0)
    {
        int bit = n % 10;
        if (bit == 1)
            dec = dec + pow(2, i);
        n = n / 10;
        i++;
    }
    cout << dec << endl;
    return 0;
}
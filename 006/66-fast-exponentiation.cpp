#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int fastExpo(int a, int n)
{
    int result = 1;

    while (n > 0)
    {
        if (n & 1)
            result = (1LL * result * a);
        a *= (1LL * a);
        n >>= 1; // right shift i.e divide by 2
    }

    return result;
}
int main()
{
    cout << fastExpo(3, 3);
    return 0;
}
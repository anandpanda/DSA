#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int modExpo(int a, int n, int m)
{
    int result = 1;

    if (n == 0)
        return 1;
    while (n > 0)
    {
        if (n & 1)
            result = (1LL * result * a) % m;
        a = (1LL * a * a) % m;
        n >> 1; // right shift i.e divide by 2
    }

    return result;
}
int main()
{

    return 0;
}
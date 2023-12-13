#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Euclid Algorithm

// lcm(a,b)*gcd(a,b) = a*b

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // while (a != b)
    // {
    //     if (a > b)
    //         a -= b;
    //     if (b > a)
    //         b -= a;
    // }
    while (b != 0)
    {
        int temp = a % b;
        a = b, b = temp;
    }
    return a; // or return b (as a==b)
}

int main()
{
    int a = 72, b = 11;
    cout << "The GCD of " << a << " and " << b << " : " << gcd(a, b);
    return 0;
}
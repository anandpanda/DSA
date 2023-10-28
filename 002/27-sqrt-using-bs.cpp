#include <iostream>
#include <cmath>
using namespace std;

long long int sqrtInt(long long int n)
{
    long long int s = 0, e = (n / 2) + 1, m, root;
    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (m * m == n)
            return m;
        else if (m * m > n)
            e = m - 1;
        else
        {
            root = s;
            s = m + 1;
        }
    }
    return root;
}

double sqrt(long long int n, int p)
{
    double root = sqrtInt(n);
    int s = 1;
    while (s <= p)
    {
        for (double i = root; i * i <= n; i += pow(0.1, s))
            root = i;
        s++;
    }
    return root;
}

int main()
{
    long long int n;
    int p;
    cout << "Enter a number : ";
    cin >> n;
    cout << "Enter precision : ";
    cin >> p;
    cout << "Square root of " << n << " is " << sqrt(n, p);

    return 0;
}
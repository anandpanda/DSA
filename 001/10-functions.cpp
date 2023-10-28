#include <iostream>
using namespace std;

int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

// function signature
int ncr(int n, int r)
{
    // function body
    int res = (fact(n)) / ((fact(r)) * (fact(n - r)));
    return res;
}

// printing upto n
void printnum(int n)
{
    for (int i = 1; i <= n; i++)
        cout << i << "  ";

    return; // return can be written in void functions but with no arguments
}

int main()
{
    //  nCr :

    int n, r;
    cout << "Enter n : ";
    cin >> n;
    cout << "Enter r : ";
    cin >> r;

    cout << endl
         << n << "C" << r << " = " << ncr(n, r) << endl; // function call

    return 0;
}
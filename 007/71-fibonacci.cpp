#include <iostream>
using namespace std;

//T.C = O(2^n)

int fibonacciAt(int pos)
{
    if (pos <= 1)
        return pos;
    return (fibonacciAt(pos - 2) + fibonacciAt(pos - 1));
}

void fibonacciUpto(int terms)
{
    static int n1 = -1, n2 = 1, n3;
    if (terms > 0)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        cout << n3 << " ";
        fibonacciUpto(terms - 1);
    }
}

int main()
{
    int terms = 6;
    fibonacciUpto(terms);
    cout << endl
         << fibonacciAt(4);
    return 0;
}
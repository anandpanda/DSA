#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp = 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            temp = 0;
            cout << "not prime";
            break;
        }
    }
    if (temp == 1)
        cout << "prime";

    return 0;
}
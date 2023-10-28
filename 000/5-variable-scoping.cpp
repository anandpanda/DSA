#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    cout << a << endl;

    if (true)
    {
        cout << a << endl;
    }
    if (true)
    {
        int a = 3;
        cout << a << endl;
    }
    if (true)
    {
        int b = 7;
        cout << b << endl;
    }
    cout << a << endl;
    // cout << b << endl;

    if (1)
    {
        int b;
        if (1)
        {
            int b;
            if (1)
            {
                int b;
                cout << b << endl;
            }
        }
    }
    return 0;
}




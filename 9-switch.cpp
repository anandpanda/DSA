#include <iostream>
using namespace std;

int main()
{

    // Simple CALCULATOR:

    float a, b, res;
    char op;
    cin >> a >> op >> b;
    switch (op) // cannot pass float/string
    {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / (float)b;
        break;
    case '%':
        res = (int)a % (int)b;
        break;
    }
    cout << a << " " << op << " " << b << " = " << res << endl;

    // No. of Notes:

    int amt;
    cout << "Enter amount : ";
    cin >> amt;
    int d100 = 0, d50 = 0, d20 = 0, d1 = 0;

    switch (amt >= 100)
    {
    case 1:

        d100 = amt / 100;
        amt -= d100 * 100;
        d50 = amt / 50;
        amt -= d50 * 50;
        d20 = amt / 20;
        amt -= d20 * 20;
        d1 = amt;
        break;

    case 0:
        switch (amt >= 50)
        {
        case 1:
            d50 = amt / 50;
            amt -= d50 * 50;
            d20 = amt / 20;
            amt -= d20 * 20;
            d1 = amt;
            break;
        case 0:
            switch (amt >= 20)
            {
            case 1:
                d20 = amt / 20;
                amt -= d20 * 20;
                d1 = amt;
                break;
            case 0:
                switch (amt >= 1)
                {
                case 1:
                    d1 = amt;
                    break;
                case 0:
                    cout << "Enter amount > 0 " << endl;
                    break;
                }
                break;
            }
            break;
        }
        break;
    }
    if (d100 != 0)
        cout << "Denomination of 100 : " << d100 << endl;
    if (d50 != 0)
        cout << "Denomination of 50 : " << d50 << endl;
    if (d20 != 0)
        cout << "Denomination of 20 : " << d20 << endl;
    if (d1 != 0)
        cout << "Denomination of 1 : " << d1 << endl;
    return 0;
}
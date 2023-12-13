#include <iostream>
using namespace std;

int pow(int base, int power)
{
    if (base == 0 && power == 0)
        return -1;
    else if (base == 0)
        return 0;
    else if (power == 0)
        return 1;

    return base * pow(base, power - 1);
}

int main()
{
    cout << pow(2, 2);

    return 0;
}
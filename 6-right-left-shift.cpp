#include <iostream>
using namespace std;

/*
1) Each left shift multiplies the num by 2.
2) Each right shift divides the num by 2.
3) Valid when the num is small and not very large.
4) In case of very large value,after shifting the most significant bit may become 1,resulting in a negative num.
5) In case of positive numbers, padding is always with 0.
6) In case of negative numbers, padding is compiler dependent.
*/

int main()
{

    cout << (17 >> 1) << endl;
    cout << (17 >> 2) << endl;
    cout << (19 << 1) << endl;
    cout << (19 << 2) << endl;

    return 0;
} 
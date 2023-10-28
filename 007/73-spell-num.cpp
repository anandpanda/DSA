#include <iostream>
using namespace std;

void spellNum(int num, string arr[])
{
    if (num == 0)
        return;
    spellNum(num / 10, arr);
    cout << arr[num % 10] << " ";
}

int main()
{
    string arr[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int num = 6122003;

    spellNum(num, arr);

    return 0;
}
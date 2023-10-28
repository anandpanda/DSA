#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string add(string a, int n, string b, int m)
{
    int carry = 0;
    string addition;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0)
    {
        int x = a[i] - '0' + b[j] - '0' + carry;
        addition.push_back((x % 10) + '0');
        carry = x / 10;
        i--, j--;
    }
    while (i >= 0)
    {
        int x = a[i] - '0' + carry;
        addition.push_back((x % 10) + '0');
        carry = x / 10;
        i--;
    }
    while (j >= 0)
    {
        int x = b[j] - '0' + carry;
        addition.push_back((x % 10) + '0');
        carry = x / 10;
        j--;
    }
    addition.push_back(carry + '0');

    while (addition[addition.size() - 1] == '0')
        addition.pop_back();
    reverse(addition.begin(), addition.end());
    return addition;
}

int main()
{
    string num1 = "090035", num2 = "227";
    cout << add(num1, 6, num2, 3);

    return 0;
}
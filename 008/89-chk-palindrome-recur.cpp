#include <iostream>
using namespace std;

bool chkPalindrome(string s, int i, int j)
{
    if (i > j)
        return true;
    else if (s[i] != s[j])
        return false;
    else
        return chkPalindrome(s, i + 1, j - 1);
}

int main()
{
    string str = "MOMDAD";
    if (chkPalindrome(str, 0, str.length() - 1))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
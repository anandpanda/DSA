#include <iostream>
using namespace std;

string validLower(string str)
{
    string valid = "";   //string is a class

    // removing special chars
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] >= 0 && str[i] <= 9)
            valid.push_back(str[i]);
    }

    // converting to lowercase
    for (int i = 0; i < valid.length(); i++)
    {
        if ((valid[i] >= 'A' && valid[i] <= 'Z'))
            valid[i] += 32;
    }

    return valid;
}

bool chkPalindrome(string str)
{
    int len = str.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    string str1 = "Anand Panda";
    string str2 = "noon NOON";

    cout << str1 << " : " << chkPalindrome(validLower(str1)) << endl;
    cout << str2 << " : " << chkPalindrome(validLower(str2)) << endl;

    return 0;
}
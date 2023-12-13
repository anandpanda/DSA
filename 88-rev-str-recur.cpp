#include <iostream>
// #include <vector>
// #include <algorithm>
using namespace std;

void RecurStrRev(string &str, int i = 0)
{
    if (i > str.length() - i - 1)
        return;
    else
    {
        swap(str[i], str[str.length() - i - 1]);
        i++;
    }
    RecurStrRev(str, i);
}

int main()
{
    string s = "Anand Panda";
    RecurStrRev(s);
    cout << s;
    return 0;
}
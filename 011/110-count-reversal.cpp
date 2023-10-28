#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "}{{}}{{{";
    if (s.length() % 2)
        cout << -1 << endl;
    else
    {
        int open, close, rev;
        open = close = rev = 0;

        for (char ch : s)
        {
            if (ch == '{')
                open++;
            else
            {
                if (!open)
                    close++;
                else
                    open--;
            }
        }
        rev = (open + 1) / 2 + (close + 1) / 2;
        cout << rev << endl;
    }

    return 0;
}
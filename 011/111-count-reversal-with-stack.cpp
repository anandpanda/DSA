#include <bits/stdc++.h>
using namespace std;

int reversal(string s)
{
    if (s.length() % 2)
        return -1;
    stack<char> st;
    int open, close, rev;
    open = close = rev = 0;
    for (char ch : s)
    {
        if (ch == '{')
            st.push(ch);
        else
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                st.push(ch);
        }
    }
    for (; !st.empty(); st.pop())
    {
        char ch = st.top();
        if (ch == '{')
            open++;
        else
            close++;
    }
    return (open + 1) / 2 + (close + 1) / 2;
}

int main()
{
    string s = "}{{}}{{{}}";
    cout << reversal(s) << endl;
    return 0;
}
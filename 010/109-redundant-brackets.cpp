#include <bits/stdc++.h>
using namespace std;

bool redundantBrackets(string s)
{
    stack<char> st;
    bool ans;
    for (char ch : s)
    {
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);
        else
        {
            if (ch == ')')
            {
                ans = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                        ans = false;
                    st.pop();
                }
                if (ans)
                    return ans;
                st.pop();
            }
        }
    }
    return ans;
}

int main()
{
    string s = "((a+b))"; // valid expression
    if (redundantBrackets(s))
        cout << "Present";
    else
        cout << "Not Present";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> &st)
{
    if (st.empty())
        return;
    int top = st.top();
    st.pop();
    printStack(st);
    cout << top << " ";
    st.push(top);
}

void insertAtBottom(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(top);
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    stack<int> st;
    for (int i : v)
        st.push(i);
    insertAtBottom(st, 0);
    printStack(st);

    return 0;
}

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

void place(stack<int> &st, int val)
{
    if (st.empty() || (!st.empty() && st.top() <= val))
    {
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    place(st, val);
    st.push(top);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;
    int top = st.top();
    st.pop();
    sortStack(st);
    place(st, top);
}

int main()
{
    vector<int> v{1,5,3,4,2,8};
    stack<int> st;
    for (int i : v)
        st.push(i);
    sortStack(st);
    printStack(st);

    return 0;
}
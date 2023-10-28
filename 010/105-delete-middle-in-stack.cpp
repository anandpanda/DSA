#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void delMiddle(stack<int> &st, int size, int count = 0)
{
    if (count == size / 2)
    {
        st.pop();
        return;
    }
    int top = st.top();
    st.pop();
    delMiddle(st, size, count + 1);
    st.push(top);
}

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

int main()
{
    vector<int> v{1, 2, 3, 4};
    stack<int> st;
    for (int i : v)
        st.push(i);
    delMiddle(st, st.size());
    printStack(st);
    cout << endl;
    printStack(st);
    return 0;
}
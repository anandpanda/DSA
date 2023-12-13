#include <bits/stdc++.h>
using namespace std;

// M is a matrix (nxn) which shows who knows whom diagonal is always 0 (ignore)

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);
    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (M[a][b])
            st.push(b);
        else
            st.push(a);
    }
    int candidate = st.top();
    for (int j = 0; j < n; j++)
    {
        if (candidate != j)
            if (!M[j][candidate] || M[candidate][j])
                return -1;
    }
    return candidate;
}

int main()
{
    vector<vector<int>> M = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    cout << celebrity(M, 3);
    return 0;
}
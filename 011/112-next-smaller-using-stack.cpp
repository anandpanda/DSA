#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{2, 1, 4, 3, 2};
    stack<int> s;
    s.push(-1);
    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (s.top() >= v[i])
            s.pop();
        ans[i] = s.top();
        s.push(v[i]);
    }

    for (int i : ans)
        cout << i << " ";
    return 0;
}
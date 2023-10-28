#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// by sorting
int duplicate(vector<int> v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++)
        if (v[i] == v[i + 1])
            return v[i];
    return -1;
}

int main()
{
    vector<int> v{1, 3, 4, 2, 2};
    cout << duplicate(v);
    return 0;
}
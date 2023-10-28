#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// by positioning
int duplicate(vector<int> v)
{
    while (v[0] != v[v[0]])
        swap(v[0], v[v[0]]);
    return v[0];
}

int main()
{
    vector<int> v{1, 3, 4, 2, 2};
    cout << duplicate(v);
    return 0;
}
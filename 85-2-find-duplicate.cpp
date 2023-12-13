#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// by marking visited
int duplicate(vector<int> v)
{
    // int ans = -1;
    for (int i = 0; i < v.size(); i++)
    {
        int index = abs(v[i]);
        if (v[index] < 0)
            return index;
        v[index] *= -1; // marking visited
    }
    return -1;
}

int main()
{
    vector<int> v{1, 3, 4, 2, 2};
    cout << duplicate(v);
    return 0;
}
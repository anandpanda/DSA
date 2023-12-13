#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveNeg(vector<int> v)
{
    int l = 0, h = v.size() - 1;
    while (l < h)
    {
        if (v[l] < 0)
            l++;
        if (v[h] > 0)
            h--;
        else
            swap(v[l], v[h]);
    }
    for (auto i : v)
        cout << i << " ";
}

int main()
{
    vector<int> v{1, 2, -3, 4, -5, 6};
    moveNeg(v); //not necessary to be sorted

    return 0;
}
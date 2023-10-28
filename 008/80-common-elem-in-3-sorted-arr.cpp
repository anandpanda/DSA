#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int> v1, vector<int> v2, vector<int> v3)
{
    int i, j, k;
    i = j = k = 0;

    set<int> st; // for storing unique intersection
    vector<int> common;

    while (i < v1.size() && j < v2.size() && k < v3.size())
    {
        if (v1[i] == v2[j] && v1[i] == v3[k])
        {
            st.insert(v1[i]);
            i++, j++, k++;
        }

        if (i < v1.size() && (v1[i] < v2[j] || v1[i] < v3[k]))
            i++;
        if (j < v2.size() && (v2[j] < v1[i] || v2[j] < v3[k]))
            j++;
        if (k < v3.size() && (v3[k] < v1[i] || v3[k] < v2[j]))
            k++;
    }

    for (auto e : st)
        common.push_back(e);

    return common;
}

int main()
{
    vector<int> v1{1, 5, 10, 20, 30, 30, 40, 80};
    vector<int> v2{6, 7, 20, 30, 30, 80, 100};
    vector<int> v3{3, 4, 15, 20, 30, 30, 70, 80, 120};

    vector<int> result = intersection(v1, v2, v3);

    for (int e : result)
        cout << e << " ";

    return 0;
}
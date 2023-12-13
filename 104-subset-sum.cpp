#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetSum(int arr[], int size, vector<int> &v, int sum = 0, int i = 0)
{
    if (i == size)
    {
        if(find(v.begin(), v.end(),sum) == v.end()) v.push_back(sum);
        return;
    }
    // not pick
    subsetSum(arr, size, v, sum, i + 1);
    subsetSum(arr, size, v, sum + arr[i], i + 1);
}
int main()
{
    int arr[3] = {1, 2, 1};
    sort(arr, arr + 2);
    vector<int> v;
    subsetSum(arr, 3, v);
    for (int i : v)
        cout << i << " ";
    return 0;
}
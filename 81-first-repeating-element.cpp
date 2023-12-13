#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int firstRepeated(int a[], int n)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[a[i]]++;
    for (int i = 0; i < n; i++)
    {
        if (hash[a[i]] > 1)
            return i + 1;
    }
    return -1;
}

int main()
{
    int arr[7] = {1, 5, 3, 4, 3, 5, 6}, n = 7;

    cout << firstRepeated(arr, n);
    return 0;
}
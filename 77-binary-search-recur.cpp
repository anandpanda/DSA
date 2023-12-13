#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//T.C = O(log(n))

bool recurBinary(int arr[], int s, int e, int key)
{
    int m = s + (e - s) / 2;
    if (s > e)
        return false;
    if (arr[m] == key)
        return true;
    else if (arr[m] < key)
        return recurBinary(arr, m + 1, e, key);
    else
        return recurBinary(arr, s, m - 1, key);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 14};
    cout << recurBinary(arr, 0, 6, 14);
    cout << endl
         << *(&arr + 1) - arr;
    return 0;
}
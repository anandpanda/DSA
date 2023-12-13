#include <iostream>
using namespace std;

int fo(int arr[], int size, int key)
{
    int s = 0, e = size - 1, ans = -1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (arr[m] == key)
        {
            ans = m;
            e = m - 1;
        }

        else if (arr[m] < key) // key lies right of mid
            s = m + 1;

        else // key lies left of mid
            e = m - 1;
    }
    return ans;
}

int lo(int arr[], int size, int key)
{
    int s = 0, e = size - 1, ans = -1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (arr[m] == key)
        {
            ans = m;
            s = m + 1;
        }

        else if (arr[m] < key) // key lies right of mid
            s = m + 1;

        else // key lies left of mid
            e = m - 1;
    }
    return ans;
}

int main()
{

    int arr[11] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 5};
    cout << "First occurrence of 3 is at index: " << fo(arr, 11, 3) << "\n";
    cout << "Last occurrence of 3 is at index: " << lo(arr, 11, 3) << "\n";

    return 0;
}
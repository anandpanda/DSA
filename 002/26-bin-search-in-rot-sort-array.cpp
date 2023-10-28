#include <iostream>
using namespace std;

int binary(int arr[], int size, int key)
{
    int s = 0, e = size - 1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] == key)
            return m;
        else if (arr[m] < key) // key lies right of mid
            s = m + 1;
        else // key lies left of mid
            e = m - 1;
    }
    return -1;
}

int pivotrs(int arr[], int size)
{
    int s = 0, e = size - 1, m;
    while (s < e)
    {
        m = s + (e - s) / 2;
        if (arr[m] >= arr[0])
            s = m + 1;
        else
            e = m;
    }
    return s;
}
int binsearch(int arr[], int size, int key)
{
    int s = pivotrs(arr, size), e = size - 1, m;
    if (key >= arr[0] && key <= arr[s - 1])
        e = s - 1, s = 0;
    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (key == arr[m])
            return m;
        else if (key > arr[m])
            s = m + 1;
        else
            e = m - 1;
    }
    return -1;
}

int main()
{
    int arr[10] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4}, key;
    cout << "Element to be searched : ";
    cin >> key;
    cout << key << " is present at index " << binsearch(arr, 10, key);
    return 0;
}
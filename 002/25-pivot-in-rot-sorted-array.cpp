// An array is provided with first increasing and then decreasing elements
// find the position and value of the peak in the array

#include <iostream>
using namespace std;

int pivotrs(int arr[], int size)
{
    int s = 0, e = size - 1, m;
    while (s < e)
    {
        m = s + (e - s) / 2;
        if (arr[m] > arr[0])
            s = m + 1;
        else
            e = m;
    }
    return s;
}

int main()
{
    int arr[10] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    cout << "Pivot is " << arr[pivotrs(arr, 10)] << " at index " << pivotrs(arr, 10);
    return 0;
}
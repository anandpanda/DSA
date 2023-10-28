// An array is provided with first increasing and then decreasing elements
// find the position and value of the peak in the array

#include <iostream>
using namespace std;

int pivot(int arr[], int size)
{
    int s = 0, e = size - 1;
    int m = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[m] > arr[m + 1])
            s = m + 1;
        else
            e = m;
        m = s + (e - s) / 2;
    }
    return m;
}

int main()
{
    int arr[10] = {11, 9, 5, 4, 1, 0, 3, 4, 8, 10};
    cout << "Pivot is " << arr[pivot(arr, 10)] << " at index " << pivot(arr, 10);
    return 0;
}
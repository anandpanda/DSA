//An array is provided with first increasing and then decreasing elements
//find the position and value of the peak in the array

#include <iostream>
using namespace std;

int peak(int arr[], int size)
{
    int s = 0, e = size - 1, m;
    while (s < e)
    {
        m = s + (e - s) / 2;
        if (arr[m] < arr[m + 1])
            s = m + 1;
        else
            e = m;
    }
    return m;
}

int main()
{
    int arr[10] = {1, 3, 4, 8, 9, 11, 9, 5, 2, 0};
    cout << "Peak is " << arr[peak(arr, 10)] << " at index " << peak(arr, 10);
    return 0;
}
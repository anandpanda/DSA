#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int arr[], int size)
{
    int l = 0, m = 0, h = size - 1;
    while (m <= h)
    {
        if (arr[m] == 0)
        {
            swap(arr[l], arr[m]);
            l++, m++;
        }
        else if (arr[m] == 1)
            m++;
        else
        {
            swap(arr[m], arr[h]);
            h--;
        }
    }
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[10];
    cout << "Enter 0s and 1s and 2s: \n";
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    sort012(arr, 10);

    return 0;
}
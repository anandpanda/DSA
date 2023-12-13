#include <iostream>
using namespace std;

void revf(int arr[], int size) // Method 1:
{
    int s = 0, e = size - 1;
    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void revs(int arr[], int size) // Method 2:
{
    for (int i = 0; i < size / 2; i++)
        swap(arr[i], arr[size - 1 - i]);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int size = 6;
    int arr[size] = {1, 2, 3, 4, 5, 6};

    revf(arr, size);

    cout << endl;

    revs(arr, size);

    return 0;
}
#include <iostream>
using namespace std;

void swapalt(int arr[], int size)
{
    for (int i = 0; i < size - 1; i = i + 2)
        swap(arr[i], arr[i + 1]);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int size;
    cout << "Enter size : ";
    cin >> size;
    int arr[15];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    swapalt(arr, size);
    return 0;
}
#include <iostream>
using namespace std;

// sorts the array as it proceeds

void insertsort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && arr[j] < arr[j-1]; j--)
            swap(arr[j], arr[j-1]);
    }
}

int main()
{
    int arr[] = {10, 1, 7, 4, 8, 2, 11};
    insertsort(arr, 7);
    cout << "Sorted array : " << endl;
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    return 0;
}
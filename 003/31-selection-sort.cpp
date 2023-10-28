#include <iostream>
using namespace std;

// finds minimum and places them one by one

void selsort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size - 1; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int arr[] = {6, 2, 8, 4, 10};
    selsort(arr, 5);
    cout << "Sorted array : " << endl;
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
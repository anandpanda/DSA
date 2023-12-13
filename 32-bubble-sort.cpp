#include <iostream>
using namespace std;

// ith round places the ith max at its right place

void bubblesort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
}

int main()
{
    int arr[] = {6, 7, 14, 9, 10};
    bubblesort(arr, 5);
    cout << "Sorted array : " << endl;
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}
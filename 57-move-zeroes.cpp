// move all zeroes to right preserving the orderd of the non zeroes elements

#include <iostream>
using namespace std;

void move0(int arr[], int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[5] = {0, 1, 0, 3, 12};
    move0(arr, 5);
    print(arr, 5);

    return 0;
}
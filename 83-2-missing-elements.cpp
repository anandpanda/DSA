#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sorting and swaping
void missing(int arr[], int size)
{
    int i = 0;
    while (i < size)
    {
        int index = arr[i] - 1;
        if (arr[i] != arr[index])
            swap(arr[i], arr[index]);
        else
            ++i;
    }
    for (int i = 0; i < size; i++)
        if (arr[i] != i + 1)
            cout << i + 1 << " ";
}

int main()
{
    int n = 5; // array contains 1...n
    int arr[n] = {1, 3, 5, 3, 4};
    missing(arr, n);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void missing(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int index = abs(arr[i]);
        if (arr[index - 1] > 0)
            arr[index - 1] *= -1;
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            cout << i + 1 << " ";
    }
}

int main()
{
    int n = 5; // array contains 1...n
    int arr[n] = {3, 3, 3, 3, 3};
    missing(arr, n);

    return 0;
}
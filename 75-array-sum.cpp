#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arraySum(int arr[], int size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return arr[0];
    return arr[0] + arraySum(arr + 1, size - 1);
}

int main()
{
    int array[] = {2, 4, 9, 9, 9};
    cout << "Sum : " << arraySum(array, 5);

    return 0;
}
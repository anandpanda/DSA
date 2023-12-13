#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//T.C = O(n)

bool searchArr(int arr[], int size, int key)
{
    if (size == 0)
        return false;
    if (arr[0] == key)
        return true;
    else
        return searchArr(arr + 1, size - 1, key);
}

int main()
{
    int array[] = {3, 5, 1, 2, 6};
    cout << searchArr(array, 5, 7);

    return 0;
}
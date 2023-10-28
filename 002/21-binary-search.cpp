#include <iostream>
using namespace std;

int binary(int arr[], int size, int key)
{
    int s = 0, e = size - 1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] == key)
            return m;
        else if (arr[m] < key) // key lies right of mid
            s = m + 1;
        else // key lies left of mid
            e = m - 1;
    }
    return -1;
}

int main()
{

    int even[6] = {0, 2, 4, 6, 8, 10};
    int odd[5] = {1, 3, 5, 7, 9};
    cout << "Index of 4 in even is : " << binary(even, 6, 4) << "\n";
    cout << "Index of 7 in even is : " << binary(odd, 5, 7) << "\n";

    return 0;
}
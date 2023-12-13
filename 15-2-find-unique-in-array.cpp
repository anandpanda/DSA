/*You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list. 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.*/

#include <iostream>
using namespace std;

//  3 1 4 3 4
// XOR with self gives 0,  XOR with 0 gives the num back : 4 ^ 4 = 0   &   0 ^ 4 = 4
//  3 ^ 1 ^ 4 ^ 3 ^ 4 = 3 ^ 3 ^ 4 ^ 4 ^ 1 = 0 ^ 0 ^ 1 = 0 ^ 1 = 1

int findUnique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
        ans = ans ^ arr[i];
    return ans;
}

int main()
{
    int arr[15], size;
    cout << "Enter size : ";
    cin >> size;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << endl
         << findUnique(arr, size);

    return 0;
}
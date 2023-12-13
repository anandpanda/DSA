/*You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list. 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.*/

#include <iostream>
using namespace std;

int findUnique(int arr[], int size)
{
    int res;
    for (int i = 0; i < size; i++)
    {
        int flag = 1;
        for (int j = 0; j < size; j++)
        {
            if (j == i)
                continue;
            else if (arr[i] == arr[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            res = arr[i];
            break;
        }
    }
    return res;
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
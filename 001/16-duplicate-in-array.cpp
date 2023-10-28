/*You are given an array 'ARR' of size 'N' containing each
number between 1 and 'N' - 1 at least once. There is a
single integer value that is present in the array twice.
Your task is to find the duplicate integer value present in
the array.*/

#include <iostream>
using namespace std;

int main()
{

    int size = 6; //= arr.size()
    int arr[size] = {1, 2, 3, 4, 5, 3};

    // brute force:

    int count[size] = {0};
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
        if (count[arr[i]] == 2)
        {
            cout << arr[i] << endl;
            break;
        }
    }

    // better logic :

    // 1 to n-1 elements are there, and 1 element is repeated,
    // if we can make the 1 to n-1 elements 0, the repeated num will remain
    // we can xor all the elements and the again xor with 1 to n-1

    int ans = 0;
    for (int i = 0; i < size; i++)
        ans = ans ^ arr[i];
    for (int i = 1; i < size; i++)
        ans = ans ^ i;
    cout << ans << endl;
    return 0;
}
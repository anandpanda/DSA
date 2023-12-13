#include <iostream>
using namespace std;
 
 //faster (718ms)

int main()
{
    int arr1[50] = {1, 2, 2, 2, 3, 4}, arr2[50] = {2, 2, 3, 3}, res[50];
    int n = 6, m = 4;
    int i = 0, j = 0, r = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            res[r] = arr1[i];
            i++;
            j++;
            r++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    for (int i = 0; i < r; i++)
        cout << res[i] << " ";

    return 0;
}
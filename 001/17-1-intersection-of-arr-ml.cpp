#include <iostream>
using namespace std;

//(724ms)

int main()
{
    int n = 6, m = 4;
    int arr1[n] = {1, 2, 2, 2, 3, 4}, arr2[m] = {2, 2, 3, 3}, res[6];
    int r = 0, ind = 0;
    for (int i = 0; i < n; i++)
    {
        int ele = arr1[i];
        for (int j = ind; j < m; j++)
        {
            if (ele > arr2[j])
            {
                continue;
            }
            else if (ele < arr2[j])
            {
                ind = j;
                break;
            }
            else if (ele == arr2[j])
            {
                ind = j;
                res[r] = ele;
                r++;
                arr2[j] = -2147483648;
                break;
            }
        }
    }
    for (int i = 0; i < r; i++)
        cout << res[i] << " ";

    return 0;
}
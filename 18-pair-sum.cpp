// You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of
// all pairs of elements such that each sum of elements of each pair equals 'S'.

// Each pair should be sorted i.e the first value should be less than or equals to
// the second value.
// Return the list of pairs sorted in non-decreasing order of their first value.

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, s, arr[15];
    int res[7][2], r = 0;

    cout << "Enter N and S : ";
    cin >> n >> s;
    cout << "Enter " << n << " elements\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // filling a 2D array with sorted 1D arrays
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == s)
            {

                if (arr[i] < arr[j])
                {
                    res[r][0] = arr[i];
                    res[r][1] = arr[j];
                }
                else
                {
                    res[r][0] = arr[j];
                    res[r][1] = arr[i];
                }
                r++;
            }
        }
    }

    // sorting the 2D array based on first value of 1D arrays
    for (int i = 0; i < r; i++)
    {
        for (int j = i + 1; j < r; j++)
        {
            if (*(*(res + i) + 0) > *(*(res + j) + 0))
                swap(res[i], res[j]);
        }
    }

    for (int i = 0; i < r; i++)
        cout << res[i][0] << " " << res[i][1] << "\n";

        return 0;
}
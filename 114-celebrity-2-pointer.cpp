#include <bits/stdc++.h>
using namespace std;

// M is a matrix (nxn) which shows who knows whom diagonal is always 0 (ignore)

int celebrity(vector<vector<int>> &M, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (M[j][i]) // j knows i -> j is not celeb
            j--;
        else // j doesn't know i -> i is not celeb
            i++;
    } // i points to celeb
    int candidate = i;
    
    // confirm
    for (int j = 0; j < n; j++)
    {
        if (candidate != j)
            if (!M[j][candidate] || M[candidate][j])
                return -1;
    }
    return candidate;
}

int main()
{
    vector<vector<int>> M = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    cout << celebrity(M, 3);

    return 0;
}
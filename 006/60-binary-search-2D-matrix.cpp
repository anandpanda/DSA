#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binary2D(vector<vector<int>> matrix, int key)
{
    int row = matrix.size(), col = matrix[0].size();

    int s = 0, e = row * col - 1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;
        int element = matrix[m / col][m % col];
        if (element == key)
            return 1;
        else if (element > key)
            e = m - 1;
        else
            s = m + 1;
    }
    return 0;
}
int main()
{
    // sorted matrix
    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    binary2D(matrix, 16) ? cout << "Element Found" << endl : cout << "Element not Present" << endl;

    return 0;
}
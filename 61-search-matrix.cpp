// matrix is sorted row wise from left to right and column wise from top to bottom
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool search(vector<vector<int>> matrix, int key)
{
    int row = matrix.size(), rowIndex = 0;
    int col = matrix[0].size(), colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];
        if (element == key)
            return 1;
        else if (element < key)
            rowIndex++;
        else
            colIndex--;
    }
    return 0;
}

int main()
{
    vector<vector<int>> matrix{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 26}};
    search(matrix, 16) ? cout << "Element Found" << endl : cout << "Element not Present" << endl;

    return 0;
}
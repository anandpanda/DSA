// print a 2d matrix in a sine wave form - first col top to bottom and so on...

#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> arr, int mrow, int ncol)
{
    cout << "The 2D matrix is : " << endl;
    for (int row = 0; row < mrow; row++)
    {
        for (int col = 0; col < ncol; col++)
            cout << arr[row][col] << " ";
        cout << endl;
    }
    cout << endl;
}

vector<int> wavePrint(vector<vector<int>> arr, int mrow, int ncol)
{
    vector<int> result;

    print(arr, mrow, ncol);
    cout << "Wave form of the above matrix is : " << endl;
    for (int col = 0; col < ncol; col++)
    {
        if (col & 1) // odd?
        {
            for (int row = mrow - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
                result.push_back(arr[row][col]);
            }
        }
        else
        {
            for (int row = 0; row < mrow; row++)
            {
                cout << arr[row][col] << " ";
                result.push_back(arr[row][col]);
            }
        }
    }
    return result;
}

void printvec(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
int main()
{
    vector<vector<int>> arr{{1, 2}, {3, 4}};
    wavePrint(arr, 2, 2);
    // printvec(wavePrint(arr, 2, 2), 4);

    return 0;
}
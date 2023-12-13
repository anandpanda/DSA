#include <iostream>
using namespace std;

int main()
{
    int arr[8];
    cout << "Enter 0s and 1s : \n";
    for (int i = 0; i < 8; i++)
        cin >> arr[i];

    int i = 0, j = 7;
    while (arr[i] == 0)
        i++;
    while (arr[j] == 1)
        j--;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";

    return 0;
}
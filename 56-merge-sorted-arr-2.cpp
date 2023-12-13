
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr1[], int m, int arr2[], int n)
{
    int i = 0, j = 0;
    while (arr1[i] != 0) // run untill the smaller array exhausts
        i++;
    while (j < n) // run if arr2 is larger
        arr1[i++] = arr2[j++];
    sort(arr1, arr1 + m);
}

void print(int arr[], int size)
{
    cout << "Merged array is : " << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr1[8] = {1, 3, 5, 7, 9, 0, 0, 0};
    int arr2[3] = {2, 4, 6};

    merge(arr1, 8, arr2, 3);
    print(arr1, 8);

    return 0;
}
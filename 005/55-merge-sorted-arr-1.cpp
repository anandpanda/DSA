#include <iostream>
using namespace std;

void merge(int arr1[], int m, int arr2[], int n, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) //run untill the smaller array exhausts
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < m) // run if arr1 is larger
        arr3[k++] = arr1[i++];
    while (j < n) // run if arr2 is larger
        arr3[k++] = arr2[j++];
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
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[3] = {2, 4, 6};

    int arr3[8] = {0};
    merge(arr1, 5, arr2, 3, arr3);

    print(arr3, 8);

    return 0;
}
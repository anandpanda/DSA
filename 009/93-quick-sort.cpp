#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(int arr[], int s, int e)
{
    int p = rand()%(e-s+1);
    swap(arr[s+p],arr[s]);
    int pivot = arr[s];

    // place pivot at right place
    // left right part
    int i = s, j = e;
    while (i < j){
        while (arr[i] <= pivot && i<e) i++;
        while (arr[j] > pivot && j>s) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[s], arr[j]);
    //return the partition position
    return j;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;

    // partition
    int p = partition(arr, s, e);

    // sort left
    quickSort(arr, s, p - 1);
    // sort right
    quickSort(arr, p + 1, e);
}

int main()
{
    int n = 6;
    int arr[] = {2, 4, 1, 1, 6, 9};

    quickSort(arr, 0, n - 1);

    for (int i : arr)
        cout << i << " ";

    return 0;
}
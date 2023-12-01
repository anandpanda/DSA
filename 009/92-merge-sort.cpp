#include <iostream>
using namespace std;

//T.C = O(nlog(n))

void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 2;
    int len2 = e - mid + 1;

    // making two arrays
    int *first = new int[len1];
    int *second = new int[len2];
    first[len1 - 1] = second[len2 - 1] = INT_MAX; // sentinels

    // copying half arrays
    int mainIn = s;
    for (int i = 0; i < len1-1; i++)
        first[i] = arr[mainIn++];
    for (int i = 0; i < len2-1; i++)
        second[i] = arr[mainIn++];

    // merging 2 sorted arrays
    int i = 0, j = 0;
    mainIn = s;

    while (mainIn <= e)
    {
        if (first[i] < second[j])
            arr[mainIn++] = first[i++];
        else
            arr[mainIn++] = second[j++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e) // base case
        return;

    int mid = s + ((e - s) / 2);

    // sorting left part
    mergeSort(arr, s, mid);

    // sorting right part
    mergeSort(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}

int main()
{
    int arr[13] = {3, 7, 1, 0, 5, 8, 9, 1, 2, 6, 8, 2, 2};
    int n = 13;
    mergeSort(arr, 0, n - 1);
    for (int i : arr)
        cout << i << " ";

    return 0;
}
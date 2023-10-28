#include <iostream>
using namespace std;

//T.C = O(nlog(n))

void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // making two arrays
    int *first = new int[len1];
    int *second = new int[len2];

    // copying half arrays
    int mainIndex = s;
    for (int i = 0; i < (len1 + len2); i++)
    {
        if (i < len1)
            first[i] = arr[mainIndex++];
        else
            second[i - (len1)] = arr[mainIndex++];
    }
    // for (int i = 0; i < len1; i++)
    //     first[i] = arr[mainIndex++];
    // for (int i = 0; i < len2; i++)
    //     second[i] = arr[mainIndex++];

    // merging 2 sorted arrays
    int i = 0, j = 0;
    mainIndex = s;

    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
            arr[mainIndex++] = first[i++];
        else
            arr[mainIndex++] = second[j++];
    }
    while (i < len1)
        arr[mainIndex++] = first[i++];
    while (j < len2)
        arr[mainIndex++] = second[j++];

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
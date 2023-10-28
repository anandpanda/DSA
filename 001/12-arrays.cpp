// int arr[10] --> array with 10 elements.
// array name i.e arr corresponds to the starting address of the array or simply the first element (&arr[0]).
// arr[x] --> means value at address - arr + x * sizeof(arr datatype)

#include <iostream>
using namespace std;

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    // int arr[10] = {[0 ... 9] = 1}; //generating error

    int arr[10] = {1, 2, 3, 4, 5}; // all the remaining elements are initialized with 0.
    int a[10];                     // initialized with garbage values
    printarr(arr, 10);

    int ele = sizeof(arr) / sizeof(int); // not working inside above function

    printf("%u\n", &arr[0]);
    printf("%u\n", &arr[5]);
    printf("%u\n", &arr + 1);

    return 0;
}
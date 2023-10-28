#include <bits/stdc++.h>
using  namespace std;

void countSort(int arr[], int n, int p){
    int ans[n];
    int count[10] = {0};
    for(int i = 0; i < n; i++)
        count[(arr[i]/p) % 10]++;
    
    for(int i = 1; i < 10; i++) count[i] += count[i-1];

    for(int i = n-1; i >= 0; i--)
        ans[--count[(arr[i]/p) % 10]] = arr[i];
    
    for(int i = 0; i < n; i++) arr[i] = ans[i];
}

void radixSort(int arr[], int n){

    int mx = arr[0], dig = 0;
    for(int i=0; i<n; i++)
        mx = max(mx, arr[i]);
    
    while(mx) dig++, mx/=10;

    for(int p = 1, i = 1; p <= dig; p++, i*=10){
        countSort(arr, n, i);
    }
}

int main(){
    
    int arr[8] = {1, 3, 2, 33, 4, 1, 6, 4};
    radixSort(arr, 8);
    for(int i=0; i<8; i++)
        cout<<arr[i]<<" ";
    return 0;
}
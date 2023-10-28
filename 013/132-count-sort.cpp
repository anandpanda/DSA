#include <bits/stdc++.h>
using  namespace std;

void countSort(int arr[], int n){
    int mx = arr[0];
    for(int i=0; i<n; i++)
        mx = max(mx, arr[i]);

    int count[mx+1] = {0};
    for(int i=0; i<n; i++)
        count[arr[i]]++;

    for(int i=1; i<=mx; i++)
        count[i] += count[i-1];
    
    int ans[n];
    for(int i = n-1; i>=0; i--)
        ans[--count[arr[i]]] = arr[i];
    
    for(int i=0; i<n; i++)
        arr[i] = ans[i];

}

int main(){
    
    int arr[8] = {1, 3, 2, 3, 4, 1, 6, 4};
    countSort(arr, 8);
    for(int i=0; i<8; i++)
        cout<<arr[i]<<" ";

    return 0;
}
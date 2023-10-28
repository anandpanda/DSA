#include <bits/stdc++.h>
using  namespace std;

int interpolation_search(int v[], int k, int s, int e){
    if(s>e || (k<v[s] && k>v[e])) return -1;

    int i = s + (k-v[s])*(e-s)/(v[e]-v[s]);
    
    if(v[i] == k) return i;
    if(v[i] > k) return interpolation_search(v, k, s, i-1);
    return interpolation_search(v, k, i+1, e);
}

int main(){
    
    int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    cout << interpolation_search(arr, 20, 0, 15);

    return 0;
}
#include <bits/stdc++.h>
using  namespace std;

int interpolation_search(int v[], int k, int s, int e){

    while(s<=e && (k>=v[s] && k<=v[e])){
        int i = s + (k-v[s])*(e-s)/(v[e]-v[s]);
        if(v[i] == k) return i;
        else if(v[i] > k) e = i-1;
        else s = i+1;
    }
    return -1;
}

int main(){
    
    int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    cout << interpolation_search(arr, 20, 0, 14);

    return 0;
}
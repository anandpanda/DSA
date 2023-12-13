#include <bits/stdc++.h>
using  namespace std;

void insertsort(vector<double> arr, int size){
    for (int i = 1; i < size; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1])
            swap(arr[j], arr[j-- -1]);
    }
}

void bucketSort(double arr[], int n){
    vector<double> b[n];
    for(int i=0; i<n; i++){
        int bi = n*arr[i];
        b[bi].push_back(arr[i]);
    }
    for(int i=0; i<n; i++)
        insertsort(b[i], b[i].size());
    
    int index = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<b[i].size(); j++){
            arr[index++] = b[i][j];
        }
    }
}

int main(){
    
    double arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}
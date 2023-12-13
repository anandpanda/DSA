//sum of min and max ele of all subarrays of size k

#include <bits/stdc++.h>
using  namespace std;

void minMaxSum(vector<int> &arr, int k){
    deque<int> mn(k), mx(k);
    int sum = 0, size = arr.size();
    for(int i = 0; i < size; i++){
        
        if(!mx.empty() && mx.front() == i-k)
            mx.pop_front();
        if(!mn.empty() && mn.front() == i-k)
            mn.pop_front();

        while(!mx.empty() && arr[mx.back()] <= arr[i])
            mx.pop_back();
        while(!mn.empty() && arr[mn.back()] >= arr[i])
            mn.pop_back();

        mx.push_back(i);        
        mn.push_back(i);   

        if(i >= k-1){
            cout << "min : " << arr[mn.front()] << " max : " << arr[mx.front()] << endl;
            sum += arr[mn.front()] + arr[mx.front()];
        }     
    }
    cout << "sum : " << sum << endl;
}

int main(){
    
    vector<int> arr{2,5,-1,7,-3,-1,-2};
    int k = 4;
    // cout << "Sum of min and max elements of all subarrays of size k : \n" << minMaxSum(arr, k) << endl;
    minMaxSum(arr,4);

    return 0;
}
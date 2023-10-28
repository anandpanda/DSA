#include <bits/stdc++.h>
using  namespace std;

class pp{
    public:
    int petrol;
    int distance;
};

int tour(pp c[], int n){
    int s = 0, def = 0, bal = 0;
    for(int i = 0; i < n; i++){
        bal += c[i].petrol - c[i].distance;
        if(bal < 0){
            s = i + 1;
            def += bal;
            bal = 0;
        }
    }
    if(def + bal >= 0) return s;
    else return -1;
}

int main(){
    
    int n = 4;
    pp arr[n] = {{4,6}, {6,5}, {7, 3}, {4, 5}};
    cout << tour(arr, n);
    return 0;
}
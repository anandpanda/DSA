#include <bits/stdc++.h>
using namespace std;

int sm[100], eq[100], gr[100];
int kth_smallest(int v[], int k, int sz) {
    int l = 0, r = sz;
    while(1){
        cout << l << " " << r << endl;
        int n = r;
        int p = v[rand() % n];
        cout << p << endl;
        int s = 0, e = 0, g = 0;
        for(int i = 0; i < r; i++){
            if(v[i] > p) gr[g++] = v[i];
            else if(v[i] < p) sm[s++] = v[i];
            else eq[e++] = v[i];
        }

        if(s >= k){
            for(int i = 0; i < s; i++) v[i] = sm[i];
            r = s;
        }
        else if(s+e >= k) return p;
        else{
            for(int i = 0; i < g; i++) v[i] = gr[i];
            k -= s+e;
            r = g;
        }
    }
}

int main() {
    int arr[] = {4, 1, 6, 2, 8, 3};
    cout << kth_smallest(arr, 3, 6);

    return 0;
}

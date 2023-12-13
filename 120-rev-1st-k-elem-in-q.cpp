#include <bits/stdc++.h>
using  namespace std;

int n = 7, k = 3;
queue<int> q;

void revq(){
    if(q.empty()) return;
    int f = q.front();
    q.pop();
    revq();
    q.push(f);
}
void revk(int m){
    if(q.empty()) return;
    if(m==0) return;
    int f = q.front();
    q.pop();
    revk(--m);
    q.push(f);
}
void krevq(int k){
    revq();
    revk(n-k);
}

int main(){
    
    for(int i = 1; i < 8; i++) q.push(i);
    krevq(3);
    for(int i = 1; i < 8; i++) cout << q.front() << " ", q.pop();
    return 0;
}
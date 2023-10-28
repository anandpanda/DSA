#include <bits/stdc++.h>
using  namespace std;

int n = 7;
queue<int> q;

void revq(){
    if(q.empty()) return;
    int f = q.front();
    q.pop();
    revq();
    q.push(f);
}

int main(){
    
    for(int i = 1; i < 8; i++) q.push(i);
    revq();
    for(int i = 1; i < 8; i++) cout << q.front() << " ", q.pop();

    return 0;
}
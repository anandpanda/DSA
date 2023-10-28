#include <bits/stdc++.h>
using  namespace std;

int n = 7;
queue<int> q;

void revq(){
    stack<int> s;
    for(int i = 0; i < n; i++){
        s.push(q.front());
        q.pop();
    }
    for(int i = 0; i < n; i++){
        q.push(s.top());
        s.pop();
    }
}

int main(){
    
    for(int i = 1; i < 8; i++) q.push(i);
    revq();
    for(int i = 1; i < 8; i++) cout << q.front() << " ", q.pop();

    return 0;
}
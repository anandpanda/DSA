#include <bits/stdc++.h>
using  namespace std;

string fnrep(string s){
    unordered_map<char,int> mp;
    queue<int> q;
    string ans = "";

    for(int i = 0; i < s.size(); i++){
        mp[s[i]]++;
        q.push(s[i]);
        while(!q.empty()){
            if(mp[q.front()] > 1) q.pop();
            else {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()) ans.push_back('#');
    }
    return ans;
}

int main(){

    string s; cin >> s;
    cout << fnrep(s) << "\n";

    return 0;
}
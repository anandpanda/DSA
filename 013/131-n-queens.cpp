#include <bits/stdc++.h>
using namespace std;

void solve(int col, int n, vector<string> &board, vector<int> &lrow, vector<int> &ldiag, vector<int> &udiag, vector<vector<string>> &ans){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row = 0; row < n; row++){
        if(!lrow[row] && !ldiag[row+col] && !udiag[n-1 + col-row]){
            board[row][col] = 'Q';
            lrow[row] = ldiag[row+col] = udiag[n-1 + col-row] = 1;
            solve(col+1, n, board, lrow, ldiag, udiag, ans);
            board[row][col] = '.';
            lrow[row] = ldiag[row+col] = udiag[n-1 + col-row] = 0;
        }
    }
}

vector<vector<string>> nQueen(int n){
    vector<string> board(n, string(n,'.'));
    vector<vector<string>> ans;
    vector<int> lrow(n,0), ldiag(2*n-1,0), udiag(2*n-1,0);
    solve(0, n, board, lrow, ldiag, udiag, ans);
    return ans;
}

int main(){
    
    vector<vector<string>> ans = nQueen(4);
    for(auto board: ans){
        for(auto row: board){
            for(auto j: row)
                cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
        
    return 0;
}
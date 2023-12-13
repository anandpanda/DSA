#include <bits/stdc++.h>
using  namespace std;

const int R = 4, C = 5;

class row_data{
    public:
    int col, val;
    row_data* next_data;
    row_data(int c, int v) : col(c), val(v), next_data(NULL) {}
};

class row{
    public:
    int r;
    row *next_row;
    row_data *node;
    row(int i) : r(i), next_row(NULL), node(NULL) {}
};


class sparse_matrix{
    public:
    int r, c;
    vector<row*> rows;
    sparse_matrix(int n, int m, int (*mat)[C]){
        rows.resize(n);
        r = n, c = m;
        row* pr = NULL;
        for(int i = 0; i < n; i++){
            row* rw = new row(i+1);
            rows[i] = rw;
            if(pr) pr->next_row = rw;
            row_data* pd = NULL; int fl = 1;
            for(int j = 0; j < m; j++){
                if(mat[i][j]){
                    if(fl){
                        fl=0;
                        rw->node = new row_data(j+1, mat[i][j]);
                        pd = rw->node;
                    }
                    else{
                        pd->next_data = new row_data(j+1, mat[i][j]);
                        pd = pd->next_data;
                    }
                }
            }
            pr = rw;
        }
    }

    void print(){
        for(int i = 0; i < r; i++){
            cout << "Row " << i+1 << " : " << endl << endl;
            row_data* rd = rows[i]->node;
            while(rd) cout << "Col : " << rd->col << " Val : " << rd->val << endl, rd = rd->next_data;
            cout << endl;
            if(i<r-1) rd = rows[i+1]->node;
        }
    }
        
};
int main(){
    
    // cin >> n >> m;
    int smat[R][C] = { {0 , 0 , 3 , 0 , 4},
                      {0 , 0 , 5 , 7 , 0},
                      {0 , 0 , 0 , 0 , 0},
                      {0 , 2 , 6 , 0 , 0} };
    sparse_matrix sm(R, C, smat);
    sm.print();

    return 0;
}
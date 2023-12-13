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
    row *rowhead, *rowtail;

    sparse_matrix(int mat[R][C]){
        rowhead = rowtail = NULL;

        for(int i = 0; i < R; i++){
            row* rw = new row(i+1);
            if(!i) rowhead = rowtail = rw;
            else rowtail = rowtail->next_row = rw;
            
            row_data* pd = NULL; int fl = 1;
            for(int j = 0; j < C; j++){
                if(mat[i][j]){
                    if(fl){
                        fl=0;
                        rowtail->node = new row_data(j+1, mat[i][j]);
                        pd = rowtail->node;
                    }
                    else{
                        pd->next_data = new row_data(j+1, mat[i][j]);
                        pd = pd->next_data;
                    }
                }
            }
        }
    }

    void print(){
        row* r = rowhead;
        for(int i = 0; i < R; i++){
            cout << "Row " << i+1 << " : " << endl << endl;
            row_data* rd = r->node;
            while(rd){
                cout << "Col : " << rd->col << " Val : " << rd->val << endl;
                rd = rd->next_data;
            }
            cout << endl;
            r = r->next_row;
        }
    }
        
};
int main(){
    
    int smat[R][C] = { {0 , 0 , 3 , 0 , 4},
                      {0 , 0 , 5 , 7 , 0},
                      {0 , 0 , 0 , 0 , 0},
                      {0 , 2 , 6 , 0 , 0} };
    sparse_matrix sm(smat);
    sm.print();

    return 0;
}
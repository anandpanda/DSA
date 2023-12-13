#include <bits/stdc++.h>
using  namespace std;

class KQ{
    int size, k, free = 0;
    int *arr, *front, *rear, *next; 

    public:
    KQ(int K, int S){
        size = S, k = K;
        arr = new int[size];
        front = new int[k]{-1};
        rear = new int[k]{-1};
        next = new int[size];
        iota(next,next+k,1);
    }
    bool isFull(){
        return free != -1;
    }
    bool isEmpty(int q){
        return front[q-1] == -1;
    }
    void nq(int val, int qno){
        if(!isFull()){
            cout << "Overflow" << endl;
            return;
        }
        int i = free;
        free = next[i];
        if(isEmpty(qno)) front[qno-1] = i;
        else next[rear[qno-1]] = i;
        rear[qno-1] = i;
        next[i] = -1;
        arr[i] = val;
        cout << "Enqueued " << val << " into queue " << qno << endl; 
    }
    void dq(int qno){
        if(isEmpty(qno)){
            cout << "Underflow" << endl;
            return;
        }
        int i = front[qno-1];
        front[qno-1] = next[i];
        next[i] = free;
        free = i;
        cout << "Dequeued " << arr[i] << " from queue " << qno << endl;
    }

  };

int main(){
    
    KQ kq(3, 6);

    kq.nq(1,1);
    kq.nq(2,1);
    kq.dq(1);
    kq.nq(3,2);
    kq.dq(1);
    kq.dq(1);

    return 0;
}
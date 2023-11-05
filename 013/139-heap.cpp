#include <bits/stdc++.h>
using  namespace std;

class heap{
    bool minHeap;
    int a[101], size;  // 1 based indexing

public:
    heap(bool mn = false){ 
        size = 0; minHeap = mn;
        a[0] = (mn ? INT_MIN : INT_MAX);
    }

    // O(logn)
    void insert(int d){
        if(size == 100){ // heap is full
            cout << "Heap is full" << endl;
            return; 
        }
        int in = ++size;
        a[in] = d;
        while(minHeap? a[in] < a[in/2] : a[in] > a[in/2]){
            swap(a[in], a[in/2]);
            in /= 2;
        }
    }

    // O(logn)
    void del(){ // delete top node
        if(size == 0){
            cout << "Heap is empty" << endl;
            return;
        }
        int in = 1;
        a[in] = a[size--];
        while(minHeap?  (a[in] > a[in*2] || a[in] > a[in*2+1])
                     :  (a[in] < a[in*2] || a[in] < a[in*2+1])){
            if(minHeap? a[in*2] < a[in*2+1] : a[in*2] > a[in*2+1]){
                swap(a[in], a[in*2]);
                in *= 2;
            }
            else{
                swap(a[in], a[in*2+1]);
                in = in*2 + 1;
            }
        }
    }

    void heapify(){

    }

    void print(){
        for(int i=1; i<=size; i++) cout << a[i] << " ";
        cout << endl;
    }
};

int main(){
    
    heap h; // max heap
    // heap h(1) // min heap
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.del();
    h.print();


    return 0;
}
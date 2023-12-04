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


    void print(){
        for(int i=1; i<=size; i++) cout << a[i] << " ";
        cout << endl;
    }
};

void heapify(vector<int> &a, int size, int in, bool mH = false){
    if(!in) return; 

    int n = size, i = in, f = 0;
    while(!f){
        f = 1;
        if(2*i <= n){
            int x = (2*i+1 <= n);
            int y = x && (mH? a[2*i] > a[i*2+1] : a[2*i] < a[i*2+1]);
            if((mH? a[i] > a[2*i+y] : a[i] < a[2*i+y])){
                swap(a[i], a[2*i+y]);
                i = 2*i + y, f = 0;
            }
        }
    }
    heapify(a, size, in-1, mH);
}

void helpHeapSort(vector<int> &a, int in, bool mH = false){
    if(in == 1) return;
    swap(a[1], a[in]);
    heapify(a, in-1, 1, mH);
    helpHeapSort(a, in-1, mH);
}
void heapSort(vector<int> &a, int size, bool mH = false){
    heapify(a, size, size/2, mH);
    helpHeapSort(a, size, mH);
}

int main(){
    
    // heap h; // max heap
    // heap h(1) // min heap
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54); // 5

    // h.del();
    // h.pint();

    vector<int> a = {-1, 50, 62, 53, 55, -2, 54};
    int n = a.size()-1;
    // heapify(a, n, n/2, 1);

    heapSort(a, n);
    for(int i=1; i<=6; i++) cout << a[i] << " ";

    return 0;
}

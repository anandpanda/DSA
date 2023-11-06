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

void heapify(int arr[], int n, bool mH = false){
    static int in = n/2;
    if(!in) return; 
    int li = in, ri = in--, f = 0;
    while(!f && li <= n/2 
    && ri <= n/2){
        f = 1;
        if((mH? arr[li] > arr[li*2] : arr[li] < arr[li*2])){
            swap(arr[li], arr[li*2]);
            li *= 2, f = 0;
        }
        if(2*ri+1 <= n && (mH? arr[ri] > arr[ri*2+1] : arr[ri] < arr[ri*2+1])){
            swap(arr[ri], arr[ri*2+1]);
            ri = ri*2+1, f = 0;
        }
    }
    heapify(arr, n, mH);
}

int main(){
    
    heap h; // max heap
    // heap h(1) // min heap
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54); // 5

    h.del();
    // h.print();

    int arr[] = {-1, 50, 55, 53, 52, -2, 54};
    heapify(arr, 6);
    for(int i=1; i<=6; i++) cout << arr[i] << " ";
    return 0;
}

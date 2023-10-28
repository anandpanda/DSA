#include <bits/stdc++.h>
using  namespace std;

#define MS 7

class Q{
    int arr[MS];
    int frt, bk;

    public:
    Q(){frt = bk = -1;}

    bool isEmpty() { return (frt==-1 && bk==-1); }
    bool isFull() { return (bk+1)%MS == frt ? true : false; }
    void enq(int val){
        if(isFull()){
            cout << "QUEUE IS FULL!!\n";
            return;
        }
        if(isEmpty()) { frt = bk = 0; }
        else { bk = (bk+1)%MS; }
        arr[bk] = val;
    }
    void deq(){
        if(isEmpty()){
            cout << "QUEUE IS EMPTY!!\n";
            return;
        }
        if(frt == bk) { frt = bk = -1; }
        else { frt = (frt+1)%MS; }
    }

    int ft(){
        if(frt == -1){
            cout << "QUEUE IS EMPTY!!\n";
            return -1;
        }
        return arr[frt];
    }

    void print()
	{
		// Finding number of elements in queue  
		int count = (bk+MS-frt)%MS + 1;
		cout << "Queue :  ";
		for(int i = 0; i <count; i++){
			int index = (frt+i) % MS; // Index of element while travesing circularly from front
			cout << arr[index] << " ";
		}
        cout << "\n\n";
	}
};

int main(){
    
    Q q; // queue size is defined 7 at top
    q.deq();
    for(int i = 1; i < 9; i++) { q.enq(i); q.print(); }
    q.deq(); q.print();
    q.deq(); q.print();
    cout << "FRONT : " << q.ft() << "\n";
    q.enq(8); q.print();
    q.enq(9); q.print();
    q.enq(10); q.print();
    q.deq(); q.print();
    q.enq(10); q.print();
    cout << "FRONT : " << q.ft() << "\n";
    return 0;
}
#include <bits/stdc++.h>
using  namespace std;

#define MS 7

class DQ{
    int arr[MS];
    int frt, bk;

    public:
    DQ(){frt = bk = -1;}
    bool isEmpty() { return (frt==-1 && bk==-1); }
    bool isFull() { return (bk+1)%MS == frt ? true : false; }
    void pushft(int x){
        if(isFull()){
            cout << "QUEUE IS FULL!!\n";
            return;
        }
        if(isEmpty()) { frt = bk = 0; }
        else { frt = (frt+MS-1)%MS; }
        arr[frt] = x;
    }
    void pushbk(int x){
        if(isFull()){
            cout << "QUEUE IS FULL!!\n";
            return;
        }
        if(isEmpty()) { frt = bk = 0; }
        else { bk = (bk+1)%MS; }
        arr[bk] = x;
    }
    void popft(){
        if(isEmpty()){
            cout << "QUEUE IS EMPTY!!\n";
            return;
        }
        if(frt == bk) { frt = bk = -1; }
        else { frt = (frt+1)%MS; }
    }
    void popbk(){
        if(isEmpty()){
            cout << "QUEUE IS EMPTY!!\n";
            return;
        }
        if(frt == bk) { frt = bk = -1; }
        else { bk = (bk+MS-1)%MS; }
    }
    int ft(){
        if(frt == -1){
            cout << "QUEUE IS EMPTY!!\n";
            return -1;
        }
        return arr[frt];
    }
    int bck(){
        if(bk == -1){
            cout << "QUEUE IS EMPTY!!\n";
            return -1;
        }
        return arr[bk];
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
    DQ q; // queue size is defined 7 at top
    q.popft(); q.popbk();
    for(int i = 1; i <= 3; i++) { q.pushft(i); q.print(); }
    for(int i = 4; i <= 7; i++) { q.pushbk(i); q.print(); }
    q.popft(); q.print();
    q.popbk(); q.print();
    cout << "FRONT : " << q.ft() << "\n";
    cout << "BACK : " << q.bck() << "\n";
    q.pushft(8); q.print();
    q.pushbk(9); q.print();
    q.pushft(10); q.print();
    q.popbk(); q.print();
    q.pushbk(10); q.print();
    cout << "FRONT : " << q.ft() << "\n";
    cout << "BACK : " << q.bck() << "\n"; 

    return 0;
}
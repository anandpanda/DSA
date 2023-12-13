#include <bits/stdc++.h>
using namespace std;

class NStack{
    private:
        int size, n, free = 0;
        int *arr, *top, *next;

    public:
        NStack(int N, int S){
            size = S, n = N;
            arr = new int[size];
            top = new int[n]{-1};
            next = new int[size];
            for(int i = 0; i < size-1; i++) next[i] = i+1;
            next[size-1] = -1;
        }

        void push(int val, int stno)
        {
            if(free == -1){
                cout << "Overflow" << endl;
                return;
            }
            int i = free;
            free = next[i];
            arr[i] = val;
            next[i] = top[stno-1];
            top[stno-1] = i;
            cout << "Pushed " << val << " into stack " << stno << endl; 
        }
        void pop(int stno)
        {
            if(top[stno-1] == -1){
                cout << "Underflow" << endl;
                return;
            }
            int i = top[stno-1];
            cout << "Popped " << arr[i] << " from stack " << stno << endl;
            top[stno-1] = next[i];
            next[i] = free;
            free = i;
        }
    
};

int main()
{
    NStack ns(3, 6);

    ns.push(1,1);
    ns.push(2,1);
    ns.pop(1);
    ns.push(3,2);
    ns.pop(1);
    ns.pop(1);

    return 0;
}
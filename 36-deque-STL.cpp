#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d; // can store from both ends

    d.push_front(1);
    d.push_back(2);
    d.push_back(3);
    for (int i : d)
        cout << i << " ";
    cout << endl;
    // pop, at, front, back, empty applies too

    d.erase(d.begin(), d.begin() + 1); // deletes the range specified but memory isn't freed,here 1st element
    for (int i : d)
        cout << i << " ";
    return 0;
}
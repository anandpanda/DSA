#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_front(1);
    for (int i : l)
        cout << i << " ";
    cout << endl;

    //l.erase(l.begin()); // deletes the element
    // direct retrieval is not possible,we have to traverse, rest same
    return 0;
}
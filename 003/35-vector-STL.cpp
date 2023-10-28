#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    // Capacity : How much it can store; Size : How much is stored.
    // When vector is filled and another element is pushed, the elements are copied to another vector of double size, the previous one being dumped.

    cout << "Capacity : " << v.capacity() << endl;
    cout << "size : " << v.size() << endl;

    v.push_back(1);
    cout << "Capacity : " << v.capacity() << endl;
    cout << "size : " << v.size() << endl;

    v.push_back(2);
    cout << "Capacity : " << v.capacity() << endl;
    cout << "size : " << v.size() << endl;

    v.push_back(3);
    cout << "Capacity : " << v.capacity() << endl;
    cout << "size : " << v.size() << endl;

    cout << "Element at 2nd index : " << v.at(2) << endl;
    cout << "Empty or not : " << v.empty() << endl;
    cout << "1st element : " << v.front() << endl;
    cout << "Last element : " << v.back();

    vector<int> vnew(v); // copied v into vnew
    cout << endl
         << "vnew : ";
    for (int i : vnew)
        cout << i << " ";
    vector<int> same(5, 1); // 5 elements initialized with 1
    cout << endl
         << "same : ";
    for (int i : same)
        cout << i << " ";

    v.pop_back(); // capacity remains same
    cout << "\nAfter popping v : ";
    for (int i : v)
        cout << i << " ";

    vnew.clear(); // deletes all elements; capacity same
    cout << "\nAfter clearing vnew, size : " << vnew.size();

    cout << "\nv.begin : " << *v.begin(); // returns iterator/pointer to first element
    cout << "\nv.end : " << *v.end();     // returns iterator/pointer to position passing last element

    return 0;
}
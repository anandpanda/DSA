// set stores uniques elements in increasing order
// elelments cannot be modified,only be inserted or deleted

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    // setting iterator
    set<int>::iterator it = s.begin();

    // s.erase(it);
    // for (auto i : s)
    //     cout << i << " ";
    // cout << endl;

    it++;
    // deleting an element
    s.erase(it);
    for (auto i : s)
        cout << i << " ";
    cout << endl;

    // check element
    cout << "Is 5 present or not : " << s.count(5) << endl;
 
    // getting reference of an element
    set<int>::iterator itr = s.find(5);
    cout << *itr;

    return 0;
}
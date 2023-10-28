// just like dictionary in  python
// key -> value
// or a many one function
// unique keys, points to only one value
// two keys can have same value

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m;

    // inserting map
    m[1] = "Panda";
    m[13] = "is";
    m[2] = "Anand";
    m.insert({5, "God"});

    //  printing keys in sorted order
    for (auto i : m)
        cout << i.first << endl;
    cout << endl;
    // printing values in sorted order
    for (auto i : m)
        cout << i.second << endl;
    cout << endl;
    // erasing 13
    m.erase(13);
    for (auto i : m)
        cout << i.second << endl;
    // getting iterator to key
    auto it = m.find(5);
    cout << endl
         << (*it).second;

    return 0;
}
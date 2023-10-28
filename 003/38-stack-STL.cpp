#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> s; // Last in First out
    s.push("Anand");
    s.push("Panda");
    s.push("is");
    s.push("great");

    cout << "Top Element : " << s.top() << endl;
    s.pop();
    cout << "Top Element : " << s.top() << endl;
    cout << "Size : " << s.size() << endl;

    //....
    return 0;
}

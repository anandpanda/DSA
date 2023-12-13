#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q; // First in First out
    q.push("Anand");
    q.push("Panda");
    q.push("is");
    q.push("great");

    cout << "First Element : " << q.front() << endl;
    q.pop();
    cout << "First Element : " << q.front() << endl;
    cout << "Size after pop : " << q.size() << endl;

    return 0;
}
#include <iostream>
using namespace std;

void printRevCount(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printRevCount(n - 1); // tail Recursion
} // print call ... print call...

void printFwdCount(int n)
{
    if (n == 0)
        return;
    printFwdCount(n - 1); // head Recursion
    cout << n << " ";
} // call all ... print ... return ... print ... return...

int main()
{
    printRevCount(5);
    cout << endl;
    printFwdCount(5);

    return 0;
}
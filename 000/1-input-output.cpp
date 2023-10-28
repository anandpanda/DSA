#include <iostream> //importing header file

using namespace std;

int main() // main is the program file's entry point
{
    int a, b = 5;
    cout << "Hello World\n"; // std ::cout << "Hello World";
    cin >> a;
    cout << "This is Anand.\nThe value of a is " << a << endl
         << "The value of b is " << b;
    return 1;
}

//  cin doesn't read whitespace characters such as \n tab space
// cin.get() reads whitespace characters
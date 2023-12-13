#include <iostream>
using namespace std;

string removeOccurencens(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
        s.erase(s.find(part), part.length()); // takes index and no. of chars to be erased
    return s;
}

// find returns the index of first occurrence

int main()
{
    string s("daabcbaabcbc");
    string part("abc");

    cout << "The remaining string  is : " << removeOccurencens(s, part) << endl;

    return 0;
}
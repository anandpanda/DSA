#include <iostream>
using namespace std;

string replaceSpaces(string str)
{
    string s = "";
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            s += "@40"; // string concatenation
        else
            s.push_back(str[i]);
    }
    return s;
}

int main()
{
    string name = "Anand Panda";
    cout << replaceSpaces(name) << endl;
    return 0;
}
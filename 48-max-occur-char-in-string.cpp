#include <iostream>
#include <algorithm>
using namespace std;

char modeChar(string str)
{
    int countCh[26] = {0};
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            countCh[str[i] - 'a']++;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            countCh[str[i] - 'A']++;
    }
    // getting index
    char maxi = &(*max_element(countCh, countCh + 26)) - &countCh[0];
    return maxi + 'a';
}
int main()
{
    string s = "TestSample";
    // cin.getline(s,10) //to take input with spaces,tabs,newline
    char modeCh = modeChar(s);
    cout << "Maximum occuring character is '" << modeCh << "'" << endl;

    return 0;
}
#include <iostream>
#include <string.h>
using namespace std;

bool chkPalindrome(char word[], int len) // Case INsensitive
{
    for (int i = 0; i < len / 2; i++)
    {
        if ((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z') || word[i] >= 0 && word[i] <= 9)
        {
            if (word[i] != word[len - 1 - i] && (word[i] + 32) != word[len - 1 - i] && word[i] != (word[len - 1 - i] + 32))
                return false;
        }
    }
    return true;
}

int main()
{
    char word1[] = "5?36@6?35";
    cout << word1 << " : " << chkPalindrome(word1, strlen(word1)) << endl;

    char word2[] = "Mom";
    cout << word2 << " : " << chkPalindrome(word2, strlen(word2));

    return 0;
}
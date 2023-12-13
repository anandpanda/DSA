#include <iostream>
#include <string.h>
using namespace std;

bool chkPalindrome(char word[], int len)  // Case Sensitive
{

    for (int i = 0; i < len / 2; i++)
    {
        if (word[i] != word[len - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    char word1[] = "Anand";
    cout << word1 << " : " << chkPalindrome(word1, strlen(word1)) << endl;

    char word2[] = "MOM";
    cout << word2 << " : " << chkPalindrome(word2, strlen(word2));

    return 0;
}
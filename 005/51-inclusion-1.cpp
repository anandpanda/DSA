#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

bool chkEqual(int arr1[], int arr2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
            return 0;
    }
    return 1;
}

bool chkInclusion(string s1, string s2) // to check if any permutation of s2 occurs in s1
{
    // counting each character of s2
    int count2[26] = {0};
    for (int i = 0; s2[i] != '\0'; i++)
    {
        if (s2[i] >= 'a' && s2[i] <= 'z')
            count2[s2[i] - 'a']++;
        else if (s2[i] >= 'A' && s2[i] <= 'Z')
            count2[s2[i] - 'A']++;
    }

    int windowSize = s2.length();
    int j = 0;
    while (j < s1.length())
    {
        int count1[26] = {0};
        for (int i = j; i < windowSize + j; i++)
        {
            if (s1[i] >= 'a' && s1[i] <= 'z')
                count1[s1[i] - 'a']++;
            else if (s1[i] >= 'A' && s1[i] <= 'Z')
                count1[s1[i] - 'A']++;
        }
        if (chkEqual(count1, count2))
            return 1;
        j++;
    }
    return 0;
}
int main()
{
    clock_t tStart = clock();

    string s1 = "eidboaoo";
    string s2 = "oab";
    cout << "The result is : " << chkInclusion(s1, s2) << endl;
    cout << "Time taken: " << fixed << setprecision(3) << ((double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
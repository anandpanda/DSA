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
        count2[s2[i] - 'a']++;

    int windowSize = s2.length();
    int count1[26] = {0};
    int i = 0;
    // running 1st window
    while (i < windowSize && i < s1.length())
    {
        int index = s1[i] - 'a';
        count1[index]++;
        i++;
    }
    if (chkEqual(count1, count2))
        return 1;

    // moving window ahead
    while (i < s1.length())
    {
        char ch = s1[i];
        int index = ch - 'a';
        count1[index]++;

        ch = s1[i - windowSize];
        index = ch - 'a';
        count1[index]--;
        i++;
        if (chkEqual(count1, count2))
            return 1;
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
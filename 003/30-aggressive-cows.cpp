// Given an posay of length 'N' where each element denotes the position of a stall. Now you have
// 'N' stalls and an integer 'K' which denotes the number of cows that are aggressive. To prevent
// the cows from hurting each other, you need to assign the cows to the stalls, such that the
// minimum distance between any two of them is as large as possible. Return the largest minimum
// distance.

#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int pos[], int stalls, int aggcows, int mid)
{
    int cowcount = 1;
    int lastpos = pos[0];
    for (int i = 0; i < stalls; i++)
    {
        if (pos[i] - lastpos >= mid)
        {
            cowcount++;
            if (cowcount == aggcows)
                return true;
            lastpos = pos[i];
        }
    }
    return false;
}

int aggressivecows(int pos[], int stalls, int aggcows)
{
    sort(pos, pos + stalls);
    int s = 0, e = *max_element(pos, pos + stalls), m, ans = -1;
    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (isPossible(pos, stalls, aggcows, m))
        {
            ans = m;
            s = m + 1;
        }
        else
            e = m - 1;
    }
    return ans;
}

int main()
{
    int pos[] = {0, 3, 4, 7, 10, 9};
    cout << "The largest minimum distance is : " << aggressivecows(pos, 6, 3);

    return 0;
}
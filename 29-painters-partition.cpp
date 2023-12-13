// Given an lengthay/list of length 'N', where the lengthay/list represents the boards and each element of
// the given lengthay/list represents the length of each board. Some 'K' numbers of painters are
// available to paint these boards. Consider that each unit of a board takes 1 unit of time to
// paint.
// You are supposed to return the minimum time to get this job done of painting all
// the 'N' boards under a constraint that any painter will only paint the continuous sections of
// boards.

#include <iostream>
#include <numeric>
using namespace std;

bool isPossible(int length[], int boards, int painters, int mid)
{
    int paintercount = 1, minTime = 0;
    for (int i = 0; i < boards; i++)
    {
        if (minTime + length[i] <= mid)
            minTime += length[i];
        else
        {
            paintercount++;
            if (paintercount > painters || length[i] > mid)
                return false;
            minTime = length[i];
        }
    }
    return true;
}

int minimumTime(int length[], int boards, int painters)
{
    int ans = -1;
    int e = accumulate(length, length + boards, 0);
    int s = 0, m;
    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (isPossible(length, boards, painters, m))
        {
            ans = m;
            e = m - 1;
        }
        else
            s = m + 1;
    }
    return ans;
}

int main()
{
    int length[] = {5, 5, 5, 5};
    cout << "The minimum time to get this job done is : " << minimumTime(length, 4, 2);

    return 0;
}
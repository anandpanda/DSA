// ways to climb n stairs by 1 or 2 steps at a time.

#include <iostream>
using namespace std;

int climbStairs(int stairs)
{
    if (stairs < 0)
        return 0;
    if (stairs == 0)
        return 1;
    return climbStairs(stairs - 1) + climbStairs(stairs - 2);
}

int main()
{
    cout << climbStairs(5) << " ways to climb 5 stairs";
    return 0;
}
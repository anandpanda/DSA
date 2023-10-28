#include <iostream>
using namespace std;

int power(int m, int n)
{
    if (n == 0)
        return 1;
    if (m == 1)
        return 1;

    int ans = power(m, n / 2);
    // if n is even
    if (n % 2 == 0)
        return ans * ans;
   else
        return m * ans * ans;
}

int main()
{
    int m, n;
    cout << "Enter m, n : ";
    cin >> m >> n;

    int ans = power(m, n);
    cout << "Result is : " << ans;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n*log(log(n)))
int simpleSieve(int n) // sieve of eratosthenes
{
    int count = 0;
    vector<bool> prime(n + 1, true); // indexes as numbers, consider all as primes,false those who are not
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;
            for (int j = 2 * i; j < n; j += i)
                prime[j] = false;
        }
    }
    return count;
}

int main()
{
    cout << "The no. of primes upto 40 : " << simpleSieve(40);

    return 0;
}
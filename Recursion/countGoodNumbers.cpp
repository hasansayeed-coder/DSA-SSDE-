#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long mod = 1000000007;

    long long findPower(long long x, long long y)
    {
        long long nn = y;
        long long ans = 1;

        while (nn)
        {
            if (nn % 2 == 1)
            {
                ans = (ans * x) % mod;
                nn--;
            }

            else
            {
                x = (x * x) % mod;
                nn = nn / 2;
            }
        }

        return (ans % mod);
    }

    int countGoodNumbers(long long n)
    {

        long long odd = n / 2;
        long long even = (n / 2) + (n % 2);

        return (findPower(5, even) * findPower(4, odd)) % mod;
    }
};
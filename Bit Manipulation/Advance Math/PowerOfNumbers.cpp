#include <bits/stdc++.h>
using namespace std;

int power(int N, int R)
{

    if (R == 0)
        return 1;

    long long res = 1;
    long long base = N;
    long long mod = 1000000007;

    while (R > 0)
    {

        if ((R & 1) == 1)
        {
            res = (res * base) % mod;
        }

        base = (base * base) % mod;
        R = R >> 1;
    }

    return res;
}
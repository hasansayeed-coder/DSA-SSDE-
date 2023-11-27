#include <bits/stdc++.h>
using namespace std;

vector<int> countPrimes(int n)
{

    vector<bool> isPrime(n + 1, true);
    vector<int> ans;

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] && n % i == 0)
        {
            ans.push_back(i);
        }
    }

    return ans;
}
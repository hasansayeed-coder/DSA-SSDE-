

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fact(vector<ll> &numbers, ll &increment, ll &ans, ll &n)
{
    ans = ans * increment;

    if (ans <= n)
    {
        numbers.push_back(ans);
        increment++;
        fact(numbers, increment, ans, n);
    }

    return;
}

vector<long long> factorialNumbers(long long n)
{

    vector<ll> numbers;
    ll increment = 1;
    long long ans = 1;

    fact(numbers, increment, ans, n);

    return numbers;
}
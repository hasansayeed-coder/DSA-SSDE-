#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{

    int n = a.size();

    int xr = 0;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    int bit = 0;

    while (1)
    {
        if (((1 << bit) & xr) != 0)
        {
            break;
        }

        bit++;
    }

    int zero = 0, one = 0;

    for (int i = 0; i < n; i++)
    {

        if (((1 << bit) & a[i]) != 0)
        {
            one = one ^ a[i];
        }

        else
        {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (((1 << bit) & i) != 0)
        {
            one = one ^ i;
        }

        else
        {
            zero = zero ^ i;
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == zero)
            cnt++;
    }

    if (cnt == 2)
    {
        return {zero, one};
    }

    return {one, zero};
}
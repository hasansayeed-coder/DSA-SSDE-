#include <bits/stdc++.h>
using namespace std;

bool isKthBitSet(int n, int k)
{
    int mask = 1;

    mask = mask << (k - 1);

    if (mask & n)
        return true;

    return false;
}
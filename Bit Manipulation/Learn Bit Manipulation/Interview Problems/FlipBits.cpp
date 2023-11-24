#include <bits/stdc++.h>
using namespace std;

int flipBits(int A, int B)
{

    int cnt = 0;

    int xoredValue = A ^ B;

    while (xoredValue)
    {
        xoredValue = xoredValue & (xoredValue - 1);
        cnt++;
    }

    return cnt;
}
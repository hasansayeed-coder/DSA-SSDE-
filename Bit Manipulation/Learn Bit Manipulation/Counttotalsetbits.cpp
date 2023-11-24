#include <bits/stdc++.h>
using namespace std;

int countSet(int N)
{

    int cnt = 0;

    while (N)
    {
        N = N & (N - 1);
        cnt++;
    }

    return cnt;
}

int countSetBits(int N)
{
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;

    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        cnt += countSet(i);
    }

    return cnt;
}
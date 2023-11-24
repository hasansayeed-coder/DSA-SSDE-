#include <bits/stdc++.h>
using namespace std;

int getPosition(int N)
{

    int pos = log2(N & -N) + 1;
    return pos;
}

int setBits(int N)
{

    if (N == 0)
        return 1;

    if ((N & (N + 1)) == 0)
    {
        return N;
    }

    int pos = getPosition(~N);

    return ((1 << (pos - 1)) | N);
}
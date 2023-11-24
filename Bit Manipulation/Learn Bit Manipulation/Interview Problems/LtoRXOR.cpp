#include <bits/stdc++.h>
using namespace std;

int findXOR(int L, int R)
{

    int postXored = 0;
    int preXored = 0;

    if (R % 4 == 0)
        postXored = R;
    else if (R % 4 == 3)
        postXored = 0;
    else if (R % 4 == 2)
        postXored = R + 1;
    else if (R % 4 == 1)
        postXored = 1;

    L = L - 1;

    if (L % 4 == 0)
        preXored = L;
    else if (L % 4 == 3)
        preXored = 0;
    else if (L % 4 == 2)
        preXored = L + 1;
    else if (L % 4 == 1)
        preXored = 1;

    return preXored ^ postXored;
}
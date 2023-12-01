#include <bits/stdc++.h>
using namespace std;

bool jump_search(vector<int> &jump, int n)
{

    int reachable = 0;

    for (int i = 0; i < n; i++)
    {
        if (reachable < i)
            return false;

        reachable = max(reachable, jump[i] + i);
    }

    return true;
}
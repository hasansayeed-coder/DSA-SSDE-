#include <bits/stdc++.h>
using namespace std;

int assignCookie(vector<int> &greed, vector<int> &size)
{

    int i = 0, j = 0;
    int fullfill = 0;

    int n = greed.size();
    int m = size.size();

    sort(greed.begin(), greed.end());
    sort(size.begin(), size.end());

    while (i < n && j < m)
    {
        if (size[j] >= greed[i])
        {
            fullfill++;
            i++;
            j++;
        }

        else
        {
            j++;
        }
    }

    return fullfill;
}

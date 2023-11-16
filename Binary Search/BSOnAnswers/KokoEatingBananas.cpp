#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v)
{
    int maxElement = INT_MIN;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        if (v[i] > maxElement)
        {
            maxElement = v[i];
        }
    }

    return maxElement;
}

int calculateTotalHours(vector<int> &v, int h)
{
    int totalH = 0;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        totalH = totalH + ceil((double)(v[i]) / (double)(h));
    }

    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h)
{

    int low = 1;
    int high = findMax(v);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);

        if (totalH <= h)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return low;
}
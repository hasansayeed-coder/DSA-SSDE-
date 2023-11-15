#include <bits/stdc++.h>
using namespace std;

int findDays(vector<int> &weights, int mid)
{

    int days = 1;
    int load = 0;
    int n = weights.size();

    for (int i = 0; i < n; i++)
    {
        if (load + weights[i] <= mid)
        {
            load += weights[i];
        }

        else
        {
            days++;
            load = weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    int leastDays = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int days = findDays(weights, mid);

        if (days <= d)
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
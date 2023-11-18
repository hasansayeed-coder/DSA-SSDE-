#include <bits/stdc++.h>
using namespace std;
#define ll long long;

bool possible(vector<int> &arr, int mid, int k, int m)
{
    int n = arr.size();
    int cnt = 0;
    int noOfB = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= mid)
        {
            cnt++;
        }

        else
        {
            noOfB = noOfB + (cnt / k);
            cnt = 0;
        }
    }
    noOfB = noOfB + (cnt / k);
    return noOfB >= m;
}

int roseGarden(vector<int> arr, int k, int m)
{

    int n = arr.size();
    long long val = m * 1ll * k * 1ll;

    if (val > n)
        return -1;

    int min_days = INT_MAX;
    int max_days = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        min_days = min(min_days, arr[i]);
        max_days = max(max_days, arr[i]);
    }

    int low = min_days;
    int high = max_days;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, mid, k, m))
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

/*
    int n = arr.size();

    long long val = m * 1ll * k * 1ll;

    if (val > n)
        return -1;

    int min_days = INT_MAX;
    int max_days = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max_days)
            max_days = arr[i];
        if (arr[i] < min_days)
            min_days = arr[i];
    }

    for (int i = min_days; i <= max_days; i++)
    {
        if (possible(i, arr, k, m) == true)
        {
            return i;
        }
    }

    return -1;
*/
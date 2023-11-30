#include <bits/stdc++.h>
using namespace std;

int distinctSubKOdds(vector<int> &arr, int k)
{
    unordered_map<int, int> mpp;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] & 1)
        {
            arr[i] = 1;
        }

        else
        {
            arr[i] = 0;
        }
    }

    int sum = 0, cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];

        if (sum == k)
            cnt++;

        if (mpp.find(sum - k) != mpp.end())
        {
            cnt = cnt + mpp[sum - k];
        }

        mpp[sum]++;
    }

    return cnt;
}
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k)
{

    int maxLen = INT_MIN;

    long long sum = 0;
    map<long long, int> mpp;
    int len = 0;

    for (int i = 0; i < a.size(); i++)
    {
        sum = sum + a[i];

        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;

        if (mpp.find(rem) != mpp.end())
        {
            len = i - mpp[rem];
            maxLen = max(len, maxLen);
        }

        if (mpp.find(rem) == mpp.end())
        {
            mpp[sum] = i;
        }
    }

    return maxLen;
}

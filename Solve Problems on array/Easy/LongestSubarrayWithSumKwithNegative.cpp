#include <bits/stdc++.h>
using namespace std;
int getLongestSubarray(vector<int> &nums, int k)
{

    map<long long, int> prefixSum;

    int n = nums.size();
    long long sum = 0;

    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;
        if (prefixSum.find(rem) != prefixSum.end())
        {
            int len = i - prefixSum[rem];
            maxLen = max(maxLen, len);
        }

        if (prefixSum.find(sum) == prefixSum.end())
        {
            prefixSum[sum] = i;
        }
    }

    return maxLen;
}

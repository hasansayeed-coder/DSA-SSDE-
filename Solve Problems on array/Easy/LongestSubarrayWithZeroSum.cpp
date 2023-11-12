#include <bits/stdc++.h>
using namespace std;

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{

    int maxLen = 0;
    int len;
    map<long long, int> mpp;

    long long sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        sum = sum + arr[i];

        if (sum == 0)
        {
            maxLen = i + 1;
        }

        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                len = i - mpp[sum];
                maxLen = max(len, maxLen);
            }

            else
            {
                mpp[sum] = i;
            }
        }
    }

    return maxLen;
}
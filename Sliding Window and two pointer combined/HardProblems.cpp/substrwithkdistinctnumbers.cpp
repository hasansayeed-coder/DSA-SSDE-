#include <bits/stdc++.h>
using namespace std;

int help(vector<int> &arr, int n, int k)
{

    int l = 0, ans = 0;

    map<int, int> mpp;

    for (int r = 0; r < n; r++)
    {
        mpp[arr[r]]++;

        if (mpp.size() > k)
        {

            while (mpp.size() > k)
            {
                mpp[arr[l]]--;

                if (mpp[arr[l]] == 0)
                    mpp.erase(arr[l]);

                l++;
            }
        }

        ans = ans + (r - l + 1);
    }

    return ans;
}

int kDistinctSubarrays(vector<int> &arr, int n, int k)
{
    return help(arr, n, k) - help(arr, n, k - 1);
}
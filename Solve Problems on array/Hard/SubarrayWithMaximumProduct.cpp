#include <bits/stdc++.h>
using namespace std;

int subarrayWithMaxProduct(vector<int> &arr)
{

    int n = arr.size();

    int ans = INT_MIN;

    int prefixSum = 1;
    int suffixSum = 1;

    for (int i = 0; i < n; i++)
    {

        if (prefixSum == 0)
            prefixSum = 1;
        if (suffixSum == 0)
            suffixSum = 1;

        prefixSum = prefixSum * arr[i];
        suffixSum = suffixSum * arr[n - i - 1];

        ans = max(ans, max(prefixSum, suffixSum));
    }

    return ans;
}
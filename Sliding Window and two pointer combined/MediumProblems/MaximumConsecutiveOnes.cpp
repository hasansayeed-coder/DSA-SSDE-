#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr, int n, int k)
{

    int i = 0, countZeros = 0;
    int ans = 0;

    for (int j = 0; j < n; j++)
    {

        if (arr[j] == 0)
            countZeros++;

        while (countZeros > k)
        {
            if (arr[i] == 0)
                countZeros--;
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    return ans;
}

#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &s)
{

    int i = 0;

    int j = 0;

    int n = s.size();

    unordered_map<char, int> mpp;

    int maxLen = INT_MIN;

    while (j < n)
    {
        mpp[s[j]]++;

        while (mpp.size() > k)
        {
            mpp[s[i]]--;

            if (mpp[s[i]] == 0)
                mpp.erase(s[i]);

            i++;
        }

        maxLen = max(maxLen, j - i + 1);
        j++;
    }

    return maxLen;
}

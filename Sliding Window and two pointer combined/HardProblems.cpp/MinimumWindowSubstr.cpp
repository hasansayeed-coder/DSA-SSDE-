#include <bits/stdc++.h>
using namespace std;

string minSubstring(string &a, string &b)
{
    unordered_map<char, int> mpp;

    for (int i = 0; i < b.size(); i++)
    {
        mpp[b[i]]++;
    }

    int l = 0, r = 0, len = INT_MAX;

    int start = -1, count = mpp.size();

    while (r < a.size())
    {
        if (mpp.find(a[r]) != mpp.end())
        {
            mpp[a[r]]--;
            if (mpp[a[r]] == 0)
                count--;
        }

        if (count == 0)
        {
            while (count == 0)
            {
                if (mpp.find(a[l]) != mpp.end())
                {
                    mpp[a[l]]++;

                    if (mpp[a[l]] == 1)
                    {
                        count++;

                        if (r - l + 1 < len)
                        {
                            len = r - l + 1;
                            start = l;
                        }
                    }
                }
                l++;
            }
        }
        r++;
    }

    return a.substr(start, len);
}
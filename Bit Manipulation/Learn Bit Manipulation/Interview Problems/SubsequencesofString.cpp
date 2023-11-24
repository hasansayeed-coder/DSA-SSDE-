#include <bits/stdc++.h>
using namespace std;

vector<string> subsequences(string str)
{

    int n = str.length();

    vector<string> ans;

    for (int i = 0; i < (1 << n); i++)
    {
        string subString = "";

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                subString += str[j];
            }
        }

        if (subString.length() > 0)
            ans.push_back(subString);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

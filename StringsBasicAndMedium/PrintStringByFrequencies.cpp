#include <bits/stdc++.h>
using namespace std;

string sortByFrequency(int n, string &s)
{

    unordered_map<char, int> mpp;

    for (auto ch : s)
    {
        mpp[ch]++;
    }

    vector<pair<int, char>> hash;

    for (auto it : mpp)
    {
        hash.push_back({it.second, it.first});
    }

    sort(hash.begin(), hash.end());

    string res = "";

    for (auto it : hash)
    {
        res = res + string(it.first, it.second);
    }

    return res;
};

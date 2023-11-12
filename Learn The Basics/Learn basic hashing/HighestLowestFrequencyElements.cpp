#include <bits/stdc++.h>
using namespace std;

vector<int> getFrequencies(vector<int> &v)
{

    vector<int> output;

    unordered_map<int, int> mpp;

    for (int i = 0; i < v.size(); i++)
    {
        mpp[v[i]]++;
    }

    int minFreq = INT_MAX;
    int maxFreq = INT_MIN;

    int minElement = -1;
    int maxElement = -1;

    for (auto it : mpp)
    {
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            maxElement = it.first;
        }

        else if (it.second == maxFreq && it.first < maxElement)
        {
            maxElement = it.first;
        }

        if (it.second < minFreq)
        {
            minFreq = it.second;
            minElement = it.first;
        }

        else if (it.second == minFreq && it.first < minElement)
        {
            minElement = it.first;
        }
    }

    output.push_back(maxElement);
    output.push_back(minElement);

    return output;
}

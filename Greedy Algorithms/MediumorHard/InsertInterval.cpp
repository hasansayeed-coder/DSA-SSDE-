#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> addInterval(vector<vector<int>> &intervals, int n, vector<int> &newInterval)
{
    vector<vector<int>> result;
    int i = 0;

    while (i < n && intervals[i][1] < newInterval[0])
    {
        result.push_back(intervals[i]);
        i++;
    }

    vector<int> mI = newInterval;

    while (i < n && intervals[i][0] <= newInterval[1])
    {
        mI[0] = min(mI[0], intervals[i][0]);
        mI[1] = max(mI[1], intervals[i][1]);
        i++;
    }

    result.push_back(mI);

    while (i < n)
    {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

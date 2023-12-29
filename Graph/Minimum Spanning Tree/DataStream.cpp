#include <bits/stdc++.h>
using namespace std;

class DisjointIntervals
{
private:
    set<int> st;

public:
    DisjointIntervals()
    {
    }

    void addInteger(int val)
    {
        st.insert(val);
    }

    vector<vector<int>> getDisjointIntervals()
    {
        if (st.empty())
            return {};

        vector<vector<int>> intervals;

        for (int it : st)
        {
            if (intervals.empty())
            {
                intervals.push_back({it, it});
            }

            else
            {
                if (intervals.back()[1] + 1 == it)
                {
                    intervals[intervals.size() - 1][1] = it;
                }

                else
                {
                    intervals.push_back({it, it});
                }
            }
        }

        return intervals;
    }
};
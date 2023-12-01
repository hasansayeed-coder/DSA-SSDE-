#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b)
{
    double f = (double)a.second / a.first;
    double s = (double)b.second / b.first;

    return f > s;
}

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{

    sort(items.begin(), items.end(), comparator);

    double profit = 0;

    for (int i = 0; i < n; i++)
    {
        int wt = items[i].first;

        if (w >= wt)
        {
            w = w - wt;
            profit = profit + items[i].second;
        }

        else
        {
            double p = items[i].second;
            double y = p / wt;
            y = y * w;
            profit = profit + y;
            break;
        }
    }

    return profit;
}
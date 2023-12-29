#include <bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{

    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;

    for (int i = 1; i < n; i++)
    {

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if ((dist[u] + wt) < dist[v] && dist[u] != 1e9)
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // now for the nth relaxation

    return dist;
}
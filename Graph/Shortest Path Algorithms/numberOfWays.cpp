#include <bits/stdc++.h>
using namespace std;

int numberOfWays(int n, int m, vector<vector<int>> &edges)
{
    const int mod = 1e9 + 7;

    vector<int> ways(n), dis(n, 1e9);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    dis[0] = 0;
    ways[0] = 1;
    pq.push({dis[0], 0});

    while (pq.size() > 0)
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                ways[v] = ways[u];
                pq.push({dis[v], v});
            }

            else if (dis[v] == dis[u] + w)
            {
                ways[v] = (ways[v] + ways[u]) % mod;
            }
        }
    }

    return ways[n - 1];
}
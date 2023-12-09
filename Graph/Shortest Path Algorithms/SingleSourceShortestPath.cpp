#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>> &edges, int src)
{

    vector<int> adj[n];

    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int dist[n];

    for (int i = 0; i < n; i++)
        dist[i] = 1e9;

    dist[src] = 0;

    queue<int> pq;
    pq.push(src);

    while (!pq.empty())
    {
        int node = pq.front();
        pq.pop();

        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = 1 + dist[node];
                pq.push(it);
            }
        }
    }

    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (dist[i] != 1e9)
        {
            ans[i] = dist[i];
        }
    }

    return ans;
}
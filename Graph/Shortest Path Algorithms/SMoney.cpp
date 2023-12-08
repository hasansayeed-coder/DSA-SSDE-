#include <bits/stdc++.h>
using namespace std;

int savingMoney(int n, int source, int destination, int K, vector<vector<int>> &trains)
{
    vector<pair<int, int>> adj[n];

    for (auto it : trains)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, pair<int, int>>> pq;

    pq.push({0, {source, 0}});

    vector<int> dist(n, 1e9);

    dist[source] = 0;

    while (!pq.empty())
    {
        auto it = pq.front();
        pq.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if (stops > K)
            continue;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edw = it.second;

            if (cost + edw < dist[adjNode] && stops <= K)
            {
                dist[adjNode] = cost + edw;
                pq.push({stops + 1, {adjNode, cost + edw}});
            }
        }
    }

    if (dist[destination] == 1e9)
        return -1;

    return dist[destination];
}
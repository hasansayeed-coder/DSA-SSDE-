#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(n, 0);

        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
                continue;

            vis[node] = 1;

            sum += wt;

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];

                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }

        return sum;
    }
};

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{

    vector<vector<int>> adj[n];

    for (auto it : edges)
    {
        vector<int> temp(2);
        temp[0] = it[1];
        temp[1] = it[2];

        adj[it[0]].push_back(temp);

        temp[0] = it[0];
        temp[1] = it[2];

        adj[it[1]].push_back(temp);
    }

    Solution obj;

    int sum = obj.spanningTree(n, adj);

    return sum;
}
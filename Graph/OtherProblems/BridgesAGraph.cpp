#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,

         int timer, vector<int> &low, vector<int> &disc, int parent, vector<vector<int>> &ans)
{

    visited[node] = 1;

    low[node] = disc[node] = timer++;

    for (auto i : adj[node])
    {

        if (i == parent)
        {

            continue;
        }
        else if (!visited[i])
        {

            dfs(i, adj, visited, timer, low, disc, node, ans);

            low[node] = min(low[node], low[i]);

            if (low[i] > disc[node])
            {

                vector<int> result;

                result.push_back(node);

                result.push_back(i);

                ans.push_back(result);
            }
        }
        else
        {

            low[node] = min(low[node], disc[i]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{

    // Write your code here

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {

        int u = edges[i][0];

        int v = edges[i][1];

        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    int timer = 0;

    vector<int> low(v);

    vector<int> disc(v);

    int parent = -1;

    for (int i = 0; i < v; i++)
    {

        low[i] = -1;

        disc[i] = -1;
    }

    unordered_map<int, bool> visited;

    vector<vector<int>> ans;

    for (int i = 0; i < v; i++)
    {

        if (!visited[i])
        {

            dfs(i, adj, visited, timer, low, disc, parent, ans);
        }
    }

    return ans;
}
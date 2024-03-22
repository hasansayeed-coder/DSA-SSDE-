#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &adj, vector<int> &a, vector<int> &vis)
{

    vis[i] = 1;

    a.push_back(i);

    for (auto ne : adj[i])
    {

        if (vis[ne] != 1)
        {

            dfs(ne, adj, a, vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)

{

    // Adjacency Matrix

    vector<vector<int>> adj(V);

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];

        int v = edges[i][1];

        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    // Visited Array

    vector<int> vis(V, 0);

    vector<vector<int>> ans;

    // Traversing

    for (int i = 0; i < V; i++)
    {

        if (vis[i] != 1)
        {

            vector<int> a;

            dfs(i, adj, a, vis);

            ans.push_back(a);
        }
    }

    return ans;
}
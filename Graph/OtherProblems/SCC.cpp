#include <bits/stdc++.h>
using namespace std;
void RDFS(int node, vector<int> &vis, vector<int> rev[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : rev[node])
    {
        if (!vis[it])
            RDFS(it, vis, rev, st);
    }
    st.push(node);
}
void dfs(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj);
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<int> adj[v];
    vector<int> rev[v];

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        rev[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(v, 0);
    stack<int> st;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            RDFS(i, vis, adj, st);
    }
    int cnt = 0;
    for (int i = 0; i < v; i++)
        vis[i] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cnt++;
            dfs(node, vis, rev);
        }
    }
    return cnt;
}
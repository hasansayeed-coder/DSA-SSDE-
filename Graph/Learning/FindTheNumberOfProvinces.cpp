#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], vector<int> adjList[])
{
    vis[node] = 1;

    for (auto it : adjList[node])
    {
        if (vis[it] == 0)
        {
            dfs(it, vis, adjList);
        }
    }
}

int findNumOfProvinces(vector<vector<int>> &roads, int n)
{

    vector<int> adjList[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (roads[i][j] == 1 && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    int vis[n] = {0};

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, vis, adjList);
            cnt++;
        }
    }
    return cnt;
}
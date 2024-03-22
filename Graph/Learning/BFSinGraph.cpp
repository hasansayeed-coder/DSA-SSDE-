#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans, int node, int &n)
{
    queue<int> pq;
    pq.push(node);
    visited[node] = 1;

    while (!pq.empty())
    {
        int child = pq.front();
        ans.push_back(child);
        pq.pop();

        for (int i = 0; i < adj[child].size(); i++)
        {
            int curr_node = adj[child][i];

            if (visited[curr_node] == 0)
            {
                pq.push(curr_node);
                visited[curr_node] = 1;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{

    vector<bool> visited(n + 1, false);
    vector<int> ans;

    bfs(adj, visited, ans, 0, n);

    return ans;
}
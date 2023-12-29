#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

public:
    vector<int> parent, rank, size;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int uu = findPar(u);
        int uv = findPar(v);

        if (uu == uv)
            return;

        if (rank[uu] > rank[uv])
        {
            parent[uv] = uu;
            rank[uu]++;
        }

        else if (rank[uu] < rank[uv])
        {
            parent[uu] = uv;
            rank[uv]++;
        }

        else
        {
            parent[uu] = uv;
            rank[uv]++;
        }
    }
};

int makeGraphConnected(int n, vector<pair<int, int>> edges, int m)
{
    DisjointSet ds(n);

    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        if (ds.findPar(u) != ds.findPar(v))
        {
            ds.unionByRank(u, v);
        }
    }

    int components = 0;

    for (int i = 1; i <= n; i++)
    {
        if (ds.findPar(i) == i)
            components++;
    }

    if (m < n - 1)
        return -1;

    return components - 1;
}
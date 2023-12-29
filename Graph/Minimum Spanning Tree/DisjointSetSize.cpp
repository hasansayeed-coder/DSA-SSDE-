#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node)
    {
        if (node == findPar(node))
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int uu = findPar(u);
        int uv = findPar(v);

        if (uu == uv)
            return;

        if (rank[uu] < rank[uv])
        {
            parent[uu] = uv;
        }

        else if (rank[uu] > rank[uv])
        {
            parent[uu] = uv;
        }

        else
        {
            parent[uv] = uu;
            rank[uv]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int uu = findPar(u);
        int uv = findPar(v);

        if (uu == uv)
            return;

        if (size[uu] > size[uv])
        {
            parent[uv] = uu;
            size[uu] += size[uv];
        }

        else
        {
            parent[uu] = uv;
            size[uv] += size[uu];
        }
    }
};

int main()
{
    DisjointSet ds(7);
}
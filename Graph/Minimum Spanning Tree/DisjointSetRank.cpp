#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(node);
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
            parent[uv] = uu;
        }

        else
        {
            parent[uv] = uu;
            rank[uu]++;
        }
    }
};

int main()
{

    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findPar(3) == ds.findPar(7))
    {
        cout << "same" << endl;
    }

    else
    {
        cout << "Not Same" << endl;
    }

    ds.unionByRank(3, 7);

    if (ds.findPar(3) == ds.findPar(7))
    {
        cout << "Same" << endl;
    }

    else
    {
        cout << "Not same" << endl;
    }
    return 0;
}
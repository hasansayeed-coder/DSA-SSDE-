#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{

    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node)
    {
        if (node == parent[node])
            return node;

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
            parent[uv] = uu;
            rank[uu]++;
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
            size[uu] += size[uv];
            parent[uv] = uu;
        }

        else
        {
            size[uv] += size[uu];
            parent[uu] = uv;
        }
    }
};

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {

        int maxRow = 0;
        int maxCol = 0;

        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);

        unordered_map<int, int> stoneNodes;

        for (auto it : stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;

            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeCol] = 1;
            stoneNodes[nodeRow] = 1;
        }

        int cnt = 0;

        for (auto it : stoneNodes)
        {
            if (ds.findPar(it.first) == it.first)
            {
                cnt++;
            }
        }
        return n - cnt;
    }
};

int removeStones(vector<vector<int>> &stones)
{

    Solution obj;
    int n = stones.size();

    int ans = obj.maxRemove(stones, n);

    return ans;
}
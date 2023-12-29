#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
private:
    vector<int> parent, sz;

public:
    Disjoint(int n)
    {
        parent.clear(), sz.clear();
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
        sz.resize(n + 1, 1);
    }
    int findParent(int n)
    {
        if (parent[n] == n)
            return n;
        else
            return parent[n] = findParent(parent[n]);
    }

    void unionWork(int u, int v, int &total)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if (parentU != parentV)
        {
            if (sz[parentU] < sz[parentV])
            {
                parent[parentU] = parentV;
                sz[parentV] += sz[parentU];
            }
            else
            {
                parent[parentV] = parentU;
                sz[parentU] += sz[parentV];
            }
            --total;
        }
    }
};

vector<int> numberOfIslandII(int n, int m, vector<vector<int>> &queries, int q)
{
    Disjoint d(n * m);
    vector<int> ans;
    unordered_map<int, bool> visited;
    int total = 0;
    int deltaRow[4] = {1, -1, 0, 0};
    int deltaCol[4] = {0, 0, 1, -1};
    for (int i = 0; i < q; ++i)
    {
        int j = queries[i][0];
        int k = queries[i][1];
        int curNodeValue = j * m + k;
        if (!visited[curNodeValue])
        {
            visited[curNodeValue] = true;
            ++total;
            for (int x = 0; x < 4; ++x)
            {
                int targetJ = j + deltaRow[x];
                int targetK = k + deltaCol[x];
                if (targetJ < 0 || targetK < 0 || targetJ == n || targetK == m)
                    continue;
                else
                {
                    int targetNodeValue = targetJ * m + targetK;
                    if (!visited[targetNodeValue])
                        continue;
                    else
                        d.unionWork(curNodeValue, targetNodeValue, total);
                }
            }
        }
        ans.push_back(total);
    }
    return ans;
};

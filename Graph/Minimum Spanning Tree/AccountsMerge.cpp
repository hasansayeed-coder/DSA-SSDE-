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
            parent[uu] = uv;
            size[uv] += size[uu];
        }
    }
};

class Solution
{

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &details)
    {
        int n = details.size();
        DisjointSet ds(n);

        sort(details.begin(), details.end());

        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < details[i].size(); j++)
            {
                string mail = details[i][j];

                if (mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }

                else
                {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];

        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++)
        {
            if (mergedMail[i].size() == 0)
                continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(details[i][0]);

            for (auto it : mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{

    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);

    return ans;
}

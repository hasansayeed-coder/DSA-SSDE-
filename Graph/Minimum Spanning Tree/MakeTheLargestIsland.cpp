#include <bits/stdc++.h>
using namespace std;

class disjoint
{
public:
    vector<int> par, size;

    disjoint(int n)
    {
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
        }
    }

    int findp(int n)
    {
        if (n == par[n])
            return n;
        return par[n] = findp(par[n]);
    }

    void unionn(int u, int v)
    {
        int uu = findp(u), uv = findp(v);
        if (uu == uv)
            return;
        if (size[uu] < size[uv])
        {
            par[uu] = uv;
            size[uv] += size[uu];
        }
        else
        {
            par[uv] = uu;
            size[uu] += size[uv];
        }
    }
};
int maximumIslandSize(vector<vector<int>> &grid)
{
    int n = grid.size();
    disjoint ds(n * n);

    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] == 0)
                continue;

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, -1, 0, 1};

            for (int k = 0; k < 4; k++)
            {
                int nr = r + drow[k];
                int nc = c + dcol[k];
                if (0 <= nr && 0 <= nc && nc < n && nr < n && grid[nr][nc])
                {
                    int node = r * n + c;
                    int newn = nr * n + nc;
                    ds.unionn(node, newn);
                }
            }
        }

    int maxx = 0;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] == 1)
                continue;

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, -1, 0, 1};
            set<int> component;
            for (int k = 0; k < 4; k++)
            {
                int nr = r + drow[k];
                int nc = c + dcol[k];
                if (0 <= nr && 0 <= nc && nc < n && nr < n && grid[nr][nc])
                {
                    int newn = nr * n + nc;
                    component.insert(ds.findp(newn));
                }
            }
            int total = 0;
            for (auto i : component)
            {
                total += ds.size[i];
            }
            maxx = max(maxx, total + 1);
        }

    for (int cell = 0; cell < n * n; cell++)
    {
        maxx = max(maxx, ds.size[ds.findp(cell)]);
    }
    return maxx;
}
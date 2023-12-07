#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)

{

    // Write your code here

    int drow[] = {-1, 0, 1, 0};

    int dcol[] = {0, 1, 0, -1};

    if (matrix[src.first][src.second] == 0)
        return -1;

    if (src.first == dest.first && src.second == dest.second)
        return 0;

    int n = matrix.size();

    int m = matrix[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    dist[src.first][src.second] = 0;

    queue<pair<int, pair<int, int>>> q;

    q.push({0, {src.first, src.second}});

    while (!q.empty())
    {

        int r = q.front().second.first;

        int c = q.front().second.second;

        int dis = q.front().first;

        q.pop();

        for (int i = 0; i < 4; i++)
        {

            int nrow = r + drow[i];

            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol])
            {

                dist[nrow][ncol] = dis + 1;

                if (nrow == dest.first && ncol == dest.second)
                    return dist[nrow][ncol];

                q.push({dist[nrow][ncol], {nrow, ncol}});
            }
        }
    }

    return -1;
}
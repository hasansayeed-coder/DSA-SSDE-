#include <bits/stdc++.h>
using namespace std;

int minimumOperations(int n, int start, int end, vector<int> &a)
{
    vector<bool> visited(1000, false);
    queue<pair<int, int>> q;

    q.push({0, start});
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front().second;
        int dist = q.front().first;

        q.pop();
        if (node == end)
        {
            return dist;
        }

        for (auto i : a)
        {
            int val = (i * node) % 1000;

            if (visited[val] == false)
            {
                visited[val] = true;
                q.push({dist + 1, val});
            }
        }
    }

    return -1;
}
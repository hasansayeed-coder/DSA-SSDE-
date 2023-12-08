vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{

    vector<pair<int, int>> adj[vertices];
    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (pq.size() != 0)
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int wt = p.first;
        int node = p.second;
        for (auto it : adj[node])
        {
            int w = it.second;
            if (dist[it.first] > w + wt)
            {
                dist[it.first] = w + wt;
                pq.push({dist[it.first], it.first});
            }
        }
    }
    return dist;
}
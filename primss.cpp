#include <bits/stdc++.h>
using namespace std;
int spanningTreeSum(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0});
    // wt, node
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edN = it[1];
            if (!vis[adjNode])
            {
                pq.push({edN, adjNode});
            }
        }
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        cout << spanningTreeSum(V, adj) << "\n";

        cout << "~" << "\n";
    }

    return 0;
}
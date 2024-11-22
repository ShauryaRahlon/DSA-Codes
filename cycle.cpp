#include <bits/stdc++.h>
using namespace std;
bool detect(int src, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }
            else if (parent != adjNode)
            {
                return true;
            }
        }
    }
    return false;
}
bool isCycle(vector<vector<int>> &adj)
{
    vector<bool> vis(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis))
                return true;
        }
    }
    return false;
}
void add_Edge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        add_Edge(adj, u, v);
    }
    cout << isCycle(adj) << endl;
}
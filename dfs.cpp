#include <bits/stdc++.h>
using namespace std;
void dfsR(vector<vector<int>> &adj, vector<bool> &vis, int V)
{
    vis[V] = 1;
    cout << V << endl;
    for (auto it : adj[V])
    {
        if (!vis[it])
            dfsR(adj, vis, it);
    }
}
void dfs(vector<vector<int>> &adj, int V)
{
    vector<bool> vis(adj.size(), 0);
    dfsR(adj, vis, V);
}
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int V = 5;
    vector<vector<int>> adj(V);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    dfs(adj, 1);
}
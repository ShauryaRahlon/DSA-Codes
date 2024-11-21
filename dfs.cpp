#include <bits/stdc++.h>
using namespace std;

void dpfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    // traverse its neighbour
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dpfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfss(int V, vector<int> adj[])
{
    // if 0 indexed
    int vis[V] = {0};
    int start = 0;
    vector<int> ls;
    dpfs(start, adj, vis, ls);
    return ls;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = dfss(n, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
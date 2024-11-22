#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define all(a) a.begin(), a.end()
#define loop(i, n) for (int i = 0; i < n; i++)
#define rloop(i, m, n) for (int i = n; i >= m; i--)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
using namespace std;
const int mod = 1e9 + 7;
void bfs(vector<vector<int>> &adj, int V)
{
    queue<int> q;
    q.push(V);
    vector<bool> vis(adj.size(), 0);
    vis[V] = 1;
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

int main()
{
#ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
freopen("output1.txt", "w", stdout);
#endif
    FAST_IO;
    vector<vector<int>> adj(5);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    // addEdge(adj, 2, 4);
    cout << "Starting BFS:" << endl;
    bfs(adj, 1);
    return 0;
}
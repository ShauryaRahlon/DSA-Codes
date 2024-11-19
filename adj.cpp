#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int graph1[N][N];
// vector<int> graph2[N];
vector<pair<int, int>> graph2[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        graph1[a][b] = wt;
        graph1[b][a] = wt;
        // using adjacency list
        graph2[a].push_back({b, wt});
        graph2[b].push_back({a, wt});

    } // O(N*N) space in matrix
}
#include <bits/stdc++.h>

using namespace std;

class Prims_Algorithm
{
    void bfs(vector<pair<int, int>> adj[], int n, vector<int> &parent, vector<int> &weight, vector<bool> &isAdded)
    {
        weight[0] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int mini = INT_MAX, node;
            for (int j = 0; j < n; j++)
            {
                if (isAdded[j] == false && mini > weight[j])
                    mini = weight[j], node = j;
            }

            isAdded[node] = true;
            for (auto it : adj[node])
            {
                if (isAdded[it.first] == false && it.second < weight[it.first])
                {
                    parent[it.first] = node;
                    weight[it.first] = it.second;
                }
            }
        }
    }

public:
    vector<int> find_MST(vector<pair<int, int>> adj[], int n)
    {
        int maxn = INT_MAX;
        vector<int> parent(n, -1), weight(n, maxn);
        vector<bool> isAdded(n, false);

        bfs(adj, n, parent, weight, isAdded);
        return parent;
    }
};

int main()
{
    //n nodes and m edges
    int n, m;

    cin >> n >> m;

    //declaring adjacency list...
    vector<pair<int, int>> adj[n + 1];

    //for input...
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    Prims_Algorithm prims;
    vector<int> parent = prims.find_MST(adj, n);
    for (auto it : parent)
        cout << it << " ";
    return 0;
}
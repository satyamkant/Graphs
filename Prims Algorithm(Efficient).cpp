#include <bits/stdc++.h>

using namespace std;

class Prims_Algorithm
{
    void bfs(vector<pair<int, int>> adj[], int n, vector<int> &parent, vector<int> &weight, vector<bool> &isAdded)
    {
        weight[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            isAdded[node] = true;

            for (auto it : adj[node])
            {
                if (isAdded[it.first] == false && it.second < weight[it.first])
                {
                    parent[it.first] = node;
                    weight[it.first] = it.second;
                    pq.push({it.second, it.first});
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
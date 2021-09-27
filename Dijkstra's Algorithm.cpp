//Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

class Dijkstra_Algorithm
{
    void bfs(vector<pair<int, int>> adj[], vector<int> &dist, int s, int n)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int predist = pq.top().first; //distance to reach node from node root(0)...
            pq.pop();
            for (auto it : adj[node])
            {
                if (predist + it.second < dist[it.first])
                {
                    dist[it.first] = predist + it.second;
                    pq.push({predist + it.second, it.first});
                }
            }
        }
    }

public:
    //change this according to the constraints...
    int maxn = INT_MAX;
    vector<int> Find_path(vector<pair<int, int>> adj[], int s, int n)
    {
        vector<int> dist(n + 1, maxn);
        //setting the source distance s as 0...
        dist[s] = 0;
        bfs(adj, dist, s, n);
        return dist;
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
    //source...
    int s;
    cin >> s;

    Dijkstra_Algorithm dijkstra;
    vector<int> dist = dijkstra.Find_path(adj, s, n);
    for (auto it : dist)
        cout << it << " ";
    return 0;
}
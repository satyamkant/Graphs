#include <bits/stdc++.h>

using namespace std;

class Topo_sort
{
    void dfs_Topo_Sort(vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st, int node)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                dfs_Topo_Sort(adj, vis, st, it.first);
            }
        }
        st.push(node);
    }

public:
    stack<int> TopoSortUsing_dfs(vector<pair<int, int>> adj[], int n)
    {
        vector<int> vis(n + 1, 0);
        stack<int> st;
        //if the graph is disconnected...then this for loop will take care of that
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs_Topo_Sort(adj, vis, st, i);
            }
        }
        return st;
    }
};

class Shortest_path
{
    vector<int> bfs(vector<pair<int, int>> adj[], vector<int> &dist, int n, int source)
    {
        Topo_sort topo;
        stack<int> st = topo.TopoSortUsing_dfs(adj, n);
        dist[source] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                if (dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                    st.push(it.first);
                }
            }
        }
    }

public:
    //change this value accorinding to the constraints...
    int maxn = INT_MAX;
    vector<int> Find_path(vector<pair<int, int>> adj[], int n)
    {
        vector<int> dist(n + 1, maxn);
        //setting the source as 0...
        bfs(adj, dist, n, 0);
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
        //adj[v].push_back(u);
    }
    Shortest_path srt_path;
    vector<int> dist = srt_path.Find_path(adj, n);
    for (auto it : dist)
        cout << it << " ";
    return 0;
}

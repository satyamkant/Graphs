#include <bits/stdc++.h>

using namespace std;

class Custom_node
{
    int U, V, WT;

public:
    Custom_node(int u, int v, int wt)
    {
        U = u;
        V = v;
        WT = wt;
    }
    int u()
    {
        return U;
    }
    int v()
    {
        return V;
    }
    int wt()
    {
        return WT;
    }
};

bool comp(Custom_node a, Custom_node b)
{
    return a.wt() < b.wt();
}

class DSU
{
    vector<int> rank, parent;

public:
    //constructor...
    DSU(int n)
    {
        rank.assign(n, 0);
        parent.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findPar(int node)
    {
        return ((parent[node] == node) ? node : (parent[node] = findPar(parent[node])));
    }

    bool isSameSet(int a, int b)
    {
        return (findPar(a) == findPar(b));
    }

    void unionSet(int a, int b)
    {
        if (!isSameSet(a, b))
        {
            int parent_a = findPar(a), parent_b = findPar(b);
            if (rank[parent_a] > rank[parent_b])
            {
                parent[parent_b] = parent_a;
            }
            else
            {
                parent[parent_a] = parent_b;
                if (rank[parent_a] == rank[parent_b])
                    rank[parent_b]++;
            }
        }
    }

    int Total_disjoint()
    {
        int count = 0;
        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == i)
                count++;
        }
        return count;
    }

    int sizeof_set(int node)
    {
        int count = 0;
        int par = findPar(node);
        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == par)
                count++;
        }
        return count;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    DSU u1(n);
    vector<Custom_node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        u--;
        v--;
        edges.push_back(Custom_node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);
    vector<pair<int, int>> mst;

    int cost = 0;
    for (auto it : edges)
    {
        if (!u1.isSameSet(it.u(), it.v()))
        {
            cost += it.wt();
            u1.unionSet(it.u(), it.v());
            mst.push_back({it.u(), it.v()});
        }
    }

    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << " " << it.second << endl;
}
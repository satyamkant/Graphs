#include <bits/stdc++.h>

using namespace std;

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
    for (int i = 0; i < m; i++)
    {
        int u, v;
        //0 based index...
        cin >> u >> v;
        u1.unionSet(u, v);
    }
}

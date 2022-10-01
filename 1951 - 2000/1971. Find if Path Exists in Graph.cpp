class DSU 
{
    vector<int> parent, rank;
public:
    DSU(int n)
    {
        parent.resize(n); rank.resize(n);
        
        iota(parent.begin(), parent.end(), 0);
        for(int i: rank) i = 0;
    }
    
    int findDSU(int e)
    {
        if(parent[e] != e) parent[e] = findDSU(parent[e]);
        return parent[e];
    }
    
    void unionDSU(int u, int v)
    {
        int e1 = findDSU(u);
        int e2 = findDSU(v);
        
        if(e1 != e2)
        {
            if(rank[e1] > rank[e2]) 
                parent[e2] = e1;
            else if (rank[e1] < rank[e2])
                parent[e1] = e2;
            else 
            {
                parent[e2] = e1;
                rank[e1]++;
            }
        }
    }
    
};

class Solution 
{
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) 
    {
        DSU graph(n);
        
        for(int i=0; i<edges.size(); i++)
            graph.unionDSU(edges[i][0], edges[i][1]);
        
        return (graph.findDSU(start) == graph.findDSU(end));
    }
};

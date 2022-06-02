class Solution {
public:
    int Z = 0;
    
    void gU(vector<vector<int>>& grid, int P, int Q)
    {
        for(int i=P; i>=0; i--)
        {
            if(grid[i][Q] == 0)
            {
                grid[i][Q] = 2;
                Z += 1;
            }
            else if(grid[i][Q] == 2) continue;
            else break;
        }
    }
    
    void gD(vector<vector<int>>& grid, int P, int Q)
    {
        for(int i=P; i<grid.size(); i++)
        {
            if(grid[i][Q] == 0)
            {
                grid[i][Q] = 2;
                Z += 1;
            }
            else if(grid[i][Q] == 2) continue;
            else break;
        }
    }
    
    void gL(vector<vector<int>>& grid, int P, int Q)
    {
        for(int j=Q; j>=0; j--)
        {
            if(grid[P][j] == 0)
            {
                grid[P][j] = 2;
                Z += 1;
            }
            else if(grid[P][j] == 2) continue;
            else break;
        }
    }
    
    void gR(vector<vector<int>>& grid, int P, int Q)
    {
        for(int j=Q; j<grid[0].size(); j++)
        {
            if(grid[P][j] == 0)
            {
                grid[P][j] = 2;
                Z += 1;
            }
            else if(grid[P][j] == 2) continue;
            else break;
        }
        
    }
        
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // walls
        for(int k=0; k<walls.size(); k++)
            grid[walls[k][0]][walls[k][1]] = -1;
        
        // guards
        for(int k=0; k<guards.size(); k++)
            grid[guards[k][0]][guards[k][1]] = 1;
        
        // search entire grid for guards
        // for(int i=0; i<m; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         if(grid[i][j] == 1)
        //         {
        //             gU(grid, i-1, j); gD(grid, i+1, j);
        //             gL(grid, i, j-1); gR(grid, i, j+1);
        //         }
        //     }
        // }
        
        for(int k=0; k<guards.size(); k++)
        {
            gU(grid, guards[k][0]-1, guards[k][1]);
            gD(grid, guards[k][0]+1, guards[k][1]);
            gL(grid, guards[k][0], guards[k][1]-1);
            gR(grid, guards[k][0], guards[k][1]+1);
        }
        
        return ((m*n) - walls.size() - guards.size() - Z);        
        
    }
};

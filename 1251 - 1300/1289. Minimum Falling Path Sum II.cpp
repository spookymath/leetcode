class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        for(int i = grid.size()-2; i >= 0; i--)
        {
            for(int j=0; j<grid.size(); j++)
            {
                int m = -1;
                for(int k=0; k<grid.size(); k++)
                {
                    if(k != j)
                    {
                        if(m == -1) m = grid[i+1][k];
                        else m = min(m, grid[i+1][k]);
                    }
                }
                
                grid[i][j] += m;
            }
        }
        
        int ans = grid[0][0];
        for(int j=1; j<grid.size(); j++)
            ans = min(ans, grid[0][j]);
        
        return ans;
    }
};

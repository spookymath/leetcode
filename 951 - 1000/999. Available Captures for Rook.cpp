class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) 
    {
        int x = -1, y = -1;
        int c = 0;
        
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
                if(board[i][j] == 'R')
                {
                    x = i, y = j;
                    break;
                }
        
        // up
        for(int i=x-1; i>=0; i--)
        {
            if(board[i][y] == 'B') break;
            if(board[i][y] == 'p')
            {
                c += 1; 
                break;
            }
        }
        
        // down
        for(int i=x+1; i<8; i++)
        {
            if(board[i][y] == 'B') break;
            if(board[i][y] == 'p')
            {
                c += 1;
                break;
            }
        }
        
        // left
        for(int j=y-1; j>=0; j--)
        {
            if(board[x][j] == 'B') break;
            if(board[x][j] == 'p')
            {
                c += 1;
                break;
            }
        }
        
        // right
        for(int j=y+1; j<8; j++)
        {
            if(board[x][j] == 'B') break;
            if(board[x][j] == 'p')
            {
                c += 1;
                break;
            }
        }
        
        return c;
            
            
    }
};

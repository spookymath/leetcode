class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) 
    {
        vector<vector<int>> v;
        
        int X = toBeRemoved[0];
        int Y = toBeRemoved[1];
        
        for(int i=0; i<intervals.size(); i++)
        {
            int mn = intervals[i][0];
            int mx = intervals[i][1];
            
            if(mx <= X || mn >= Y) v.push_back({mn, mx});
            
            else
            {
                if(mn < X) v.push_back({mn, X});
                if(Y < mx) v.push_back({Y, mx});
            }
        }
        
        return v;
        
    }
};

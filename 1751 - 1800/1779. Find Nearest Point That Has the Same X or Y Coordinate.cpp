class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) 
    {
        int idx = -1;
        int val = INT_MAX;
        
        for(int i=0; i<points.size(); i++)
            if(points[i][0] == x || points[i][1] == y)
                if(abs(x-points[i][0]) + abs(y-points[i][1]) < val)
                {
                    val = abs(x-points[i][0]) + abs(y-points[i][1]);
                    idx = i;
                }
        
        return idx;
        
    }
};

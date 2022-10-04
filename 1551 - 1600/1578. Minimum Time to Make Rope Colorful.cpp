class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int cost = 0;
        int n = colors.size();
        
        for(int i=0; i<n; i++)
        {
            if(i < n-1 && colors[i] == colors[i+1])
            {
                int tmpMax = max(neededTime[i], neededTime[i+1]);
                int tmpCost = neededTime[i] + neededTime[i+1];
                
                int j = i+1;
                while(true)
                {
                    if(colors[j] == colors[j+1])
                    {
                        tmpMax = max(tmpMax, neededTime[j+1]);
                        tmpCost += neededTime[j+1];
                        j++;
                    }
                    
                    else break;
                }
                
                i = j;
                cost += (tmpCost - tmpMax);
            }
        }
        
        return cost;
    }
};

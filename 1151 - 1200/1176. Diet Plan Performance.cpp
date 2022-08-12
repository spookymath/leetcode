class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) 
    {
        int pts = 0;
        
        int sum = 0;
        for(int i=0; i<k; i++) sum += calories[i];
        
        if(sum > upper) pts += 1;
        else if(sum < lower) pts -= 1;
        
        int j = 0;
        for(int i=k; i<calories.size(); i++)
        {
            sum += calories[i] - calories[j];
            if(sum > upper) pts += 1;
            else if(sum < lower) pts -= 1;
            j += 1;
        }
        
        return pts;   
    }
};

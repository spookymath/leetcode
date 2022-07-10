class Solution {
public:
    int jump(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), 0);
        
        dp[nums.size()-1] = 0;
        for(int i=nums.size()-2; i>=0; i--)
        {
            int temp = 100000;
            for(int j = 1; j<=nums[i]; j++)
            {
                if(i + j >= nums.size()) break;
                temp = min(temp, dp[i+j]);
            }
            
            dp[i] = 1 + temp;
        }
        
        return dp[0];
        
    }
};

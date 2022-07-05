class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> ust(nums.begin(), nums.end());
        
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(ust.find(nums[i]-1) != ust.end())
                continue;
            
            int x = nums[i];
            int y = 0;
            
            while(ust.find(x) != ust.end())
            {
                x += 1;
                y += 1;
            }
            
            ans = max(ans, y);
        }
        return ans;
    }
};

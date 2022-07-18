class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int x = -1, y = -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[abs(nums[i]) - 1] < 0) x = abs(nums[i]);
            else nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        
        for(int i=0; i<nums.size(); i++)
            if(nums[i] > 0) { y = i+1; break; }
        
        return {x, y};
        
    }
};

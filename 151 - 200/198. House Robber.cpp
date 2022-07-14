class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int x = -1;
        if(nums.size() == 1) x = nums[0];
        else if(nums.size() == 2) x = max(nums[0], nums[1]);
        
        else
        {
            nums[2] += nums[0];
            x = max(nums[1], nums[2]);
            
            for(int i=3; i<nums.size(); i++)
            {
                nums[i] += max(nums[i-2], nums[i-3]);
                x = max(x, nums[i]);
            }
        }
        
        return x;
    }
};

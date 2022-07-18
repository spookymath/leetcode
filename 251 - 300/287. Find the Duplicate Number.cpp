class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int x = -1;
        for(int i=0; i<nums.size(); i++)
        {
            //int idx = abs(nums[i]) - 1;
            if(nums[abs(nums[i]) - 1] < 0) { x = abs(nums[i]); break; }
            else nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        
        return x;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> v(nums.size(), 0);
        for(int i=0; i<nums.size(); i++) v[i] = 1;
        
        // left side
        for(int i=1; i<nums.size(); i++)
            v[i] = v[i-1]*nums[i-1];
        
        int temp = 1;
        // right side
        for(int i=nums.size()-2; i>=0; i--)
        {
            temp *= nums[i+1];
            v[i] *= temp;
        }
        
        return v;
    }
};

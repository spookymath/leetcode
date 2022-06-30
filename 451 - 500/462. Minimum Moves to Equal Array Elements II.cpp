class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) return (abs(nums[0] - nums[1]));
        
        sort(nums.begin(), nums.end());
        
        if(nums.size() & 1)
        {
            int s = 0;
            int idx = (nums.size()-1)/2;
            for(int i=0; i<nums.size(); i++)
                    s += abs(nums[idx] - nums[i]);
            return s;
        }
        
        int idx1 = (nums.size()-1)/2;
        int idx2 = idx1 + 1;
        
        int s1 = 0, s2 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            s1 += abs(nums[idx1] - nums[i]);
            s2 += abs(nums[idx2] - nums[i]);
        }
        
        return min(s1, s2);
    }
};

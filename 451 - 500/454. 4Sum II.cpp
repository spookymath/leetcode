class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, 
                     vector<int>& nums3, vector<int>& nums4) 
    {
        int ans = 0;
        
        unordered_map<int, int> ump;
        
        for(int i:nums1)
            for(int j:nums2)
                ump[i+j] += 1;
        
        for(int i:nums3)
            for(int j:nums4)
                ans += ump[0 - i - j];
        
        return ans;        
    }
};

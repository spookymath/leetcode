class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = queries.size();
        vector<int> v(n);
        
        int s = 0;
        for(int i: nums) s += (i & 1) ? 0 : i;
        
        for(int i=0; i<n; i++)
        {
            int idx = queries[i][1];
            
            if(nums[idx] & 1) // odd
            {
                if(!((nums[idx] + queries[i][0]) & 1)) // even
                    s += nums[idx] + queries[i][0];
                nums[idx] += queries[i][0];
            }
            
            else // even
            {
                s -= nums[idx];
                if(!((nums[idx] + queries[i][0]) & 1)) // even
                    s += nums[idx] + queries[i][0];
                nums[idx] += queries[i][0];
            }
            
            v[i] = s;
        }
        
        return v;
    }
};

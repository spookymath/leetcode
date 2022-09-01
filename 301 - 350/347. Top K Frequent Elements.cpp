class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        unordered_map<int, int> :: iterator itr;
        for(int i: nums) mp[i] += 1;
        
        vector<vector<int>> bucket(nums.size() + 1);
        for(itr = mp.begin(); itr != mp.end(); itr++)
            bucket[itr->second].push_back(itr->first);
        
        vector<int> ans;
        for(int i=nums.size(); i>=0; i--)
        {   
            for(int j=0; j<bucket[i].size(); j++)
                ans.push_back(bucket[i][j]);
            
            k -= bucket[i].size();
            if(k == 0) break;
        }
        
        return ans;
    }
};

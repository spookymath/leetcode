class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) 
    {
        unordered_map<int, int> ump;
        
        for(int i=0; i<nums.size(); i++)
            ump[nums[i]] = i;
        
        for(int i=0; i<operations.size(); i++)
        {
            nums[ump[operations[i][0]]] = operations[i][1];
            ump[operations[i][1]] = ump[operations[i][0]];
            ump.erase(operations[i][0]);
        }
        
        return nums;
        
    }
};

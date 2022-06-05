class Solution {
public:
    int minMaxGame(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums[0];
        
        bool X = false;
        
        while(nums.size() != 1)
        {
            vector<int> newNums;
            for(int i=0; i<nums.size(); i+=2)
            {
                if(X == false)
                {
                    newNums.push_back(min(nums[i], nums[i+1]));
                    X = true;
                }
                else
                {
                    newNums.push_back(max(nums[i], nums[i+1]));
                    X = false;
                }
            }
            
            nums.clear();
            nums = newNums;
            newNums.clear();
        }
        
        return nums[0];
    }
};

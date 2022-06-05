class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        // binary search
        int L = 0;
        int H = nums.size() - 1;
        
        while(L < H)
        {
            int M = L + floor((H - L + 1)/2);
            
            if(target < nums[M]) H = M - 1l;
            else L = M;
        }
        
        return ((nums[L] == target) ? L : -1);
    }
};

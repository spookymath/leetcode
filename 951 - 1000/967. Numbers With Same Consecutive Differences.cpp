class Solution {
public:
    unordered_set<int> st;
    
    void helper(int num, int current, int sz, int k, int n)
    {
        if(sz == n)
        {
            st.insert(num);
            return;
        }
        
        if(current + k <= 9)
            helper(num*10 + (current + k), current + k, sz + 1, k, n);
        if(current - k >= 0)
            helper(num*10 + (current - k), current - k, sz + 1, k, n);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        for(int i=1; i<10; i++)
            helper(i, i, 1, k, n);
        
        vector<int> v(st.begin(), st.end());
        return v;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size() == 0 || s.size() == 1) return s.size();
        
        int ans = 1; // minimum
        
        int i = 0, j = 1;
        unordered_set<char> st;
        
        st.insert(s[i]);
        while(j != s.size())
        {
            if(st.find(s[j]) == st.end())
            {
                st.insert(s[j++]);
                ans = max(ans, (int)st.size());
            }
            
            else                                    // repeated elements
            {
                ans = max(ans, (int)st.size());     // update result
                
                while(i < j)
                {
                    if(s[i] != s[j]) st.erase(s[i++]);
                    
                    else
                    {
                        st.erase(s[i++]);
                        st.insert(s[j++]);
                        break;
                    }
                }
            }
        }
        
        return ans;       
    }
};

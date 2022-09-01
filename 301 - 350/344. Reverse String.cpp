class Solution {
public:
    void rev(vector<char>& s, int left, int right)
    {
        if(left >= right) return;
        
        rev(s, left+1, right-1);
        swap(s[left], s[right]);
    }
    
    void reverseString(vector<char>& s) 
    {
        rev(s, 0, s.size()-1);
    }
};

class Solution {
public:
    int numDecodings(string s) 
    {
        if(s.at(0) == '0') return 0;
        
        int n = s.size();
        vector<unsigned long long> v(n + 1, 0);
        
        v[n] = 1;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i] == '0') v[i] = 0;
            else
            {
                v[i] += v[i+1];
                if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
                    v[i] += v[i+2];
            }
        }        
        return v[0];
    }
};


/* Memoization : Top-Down DP
class Solution {
public:
    int decode(string s, int pos, vector<unsigned long long>& v)
    {
        // check for zeroes before size
        if(s[pos] == '0')       return 0;
        if(pos >= s.size() - 1) return 1;
        if(v[pos] > 0) return v[pos];
        
        unsigned long long d1 = decode(s, pos + 1, v);
        
        unsigned long long d2 = 0;
        string c = s.substr(pos, 2);
        
        if(stoi(c) > 0 && stoi(c) < 27) 
            d2 = decode(s, pos + 2, v);
        v[pos] = d1 + d2;
        
        return v[pos];
    }
    
    int numDecodings(string s) 
    {
        if(s.at(0) == '0') return 0;
        
        unsigned long long ans = 0;
        vector<unsigned long long> v(s.size() + 1, 0);
        
        ans = decode(s, 0, v);
        
        return ans;
    }
};
*/

/* Recursion 
class Solution {
public:
    int decode(string s, int pos)
    {
        // check for zeroes before size
        if(s[pos] == '0')       return 0;
        if(pos >= s.size() - 1) return 1;
        
        unsigned long long d1 = decode(s, pos + 1);
        
        unsigned long long d2 = 0;
        string c = s.substr(pos, 2);
        
        if(stoi(c) > 0 && stoi(c) < 27)
            d2 = decode(s, pos + 2);
        
        return d1 + d2;
    }
    
    int numDecodings(string s) 
    {
        if(s.at(0) == '0') return 0;
        
        unsigned long long ans = 0;
        ans = decode(s, 0);
        
        return ans;
    }
};
*/

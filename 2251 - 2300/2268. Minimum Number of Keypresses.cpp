class Solution {
public:
    int minimumKeypresses(string s) 
    {
        unordered_map<int, int> mp;
        unordered_map<int, int> :: iterator itr;
        for(int i=0; i<s.length(); i++) mp[s[i]-'a'] += 1;
        
        vector<int> v;
        for(itr = mp.begin(); itr != mp.end(); itr++) v.push_back(itr->second);
        
        sort(v.begin(), v.end(), greater<int>());
        
        int sum = 0;
        for(int i=0; i<v.size(); i++)
        {
            if(i<9) sum += v[i]*1;
            else if(i<18) sum += v[i]*2;
            else sum += v[i]*3;
        }
        
        return sum; 
    }
};

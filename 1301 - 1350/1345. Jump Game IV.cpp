class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        if(arr.size() == 1) return 0;
        
        vector<int> visited(arr.size(), 0);
        
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<arr.size(); i++) mp[arr[i]].push_back(i);
        
        vector<int> dp(arr.size(), 0); dp[0] = 0;
        
        queue<int> Q; Q.push(0);

        while(!Q.empty())
        {
            int idx = Q.front();
            
            if(idx == arr.size() - 1) return dp[idx];
            
            if(!visited[idx])
            {
                visited[idx] = 1;
                
                if(mp.find(arr[idx]) != mp.end())
                {
                    //vector<int> temp = mp[arr[idx]];
                    for(int i=0; i<mp[arr[idx]].size(); i++)
                    {
                        if(visited[mp[arr[idx]][i]] == 0 && dp[mp[arr[idx]][i]] == 0) 
                        {
                            dp[mp[arr[idx]][i]] = dp[idx] + 1;
                            Q.push(mp[arr[idx]][i]);
                        }

                        if(mp[arr[idx]][i] == arr.size() - 1) return dp[mp[arr[idx]][i]];
                    }
                }
                mp.erase(arr[idx]);
                
                if((idx - 1 >= 0) && visited[idx - 1] == 0 && dp[idx - 1] == 0)
                {
                    dp[idx - 1] = dp[idx] + 1;
                    Q.push(idx - 1);
                }
                
                if((idx + 1 < arr.size()) && visited[idx + 1] == 0 && dp[idx + 1] == 0)
                {
                    dp[idx + 1] = dp[idx] + 1;
                    if(idx + 1 == arr.size()) return dp[idx + 1]; 
                    Q.push(idx + 1);
                }            
            }
            
            Q.pop();
        }
        
        return dp[arr.size() - 1];
        
    }
};

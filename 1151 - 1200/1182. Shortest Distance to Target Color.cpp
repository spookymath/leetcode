class Solution {
public:
    
    void perform(vector<int>& colors, vector<int>& v, const int& k, int& N)
    {
        int j = -1;
        for(int i=0; i<N; i++)
        {
            if(colors[i] == k) { v[i] = 0; j = i;}
            else
            {
                if(j == -1) v[i] = -1;
                else v[i] = i - j;
            }          
        }

        j = N;
        for(int i=N-1; i>-1; i--)
        {
            if(colors[i] == k) j = i;
            else
            {
                if(j == N) v[i] = v[i];
                else
                {
                    if(v[i] == -1) v[i] = j - i;
                    else v[i] = min(v[i], j - i);
                }
            }
        }
    }
    
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) 
    {
        int N = colors.size();
        vector<int> v1(N), v2(N), v3(N);
        
        for(int i=0; i<N; i++)
            v1[i] = -1, v2[i] = -1, v3[i] = -1;
        
        perform(colors, v1, 1, N);
        perform(colors, v2, 2, N);
        perform(colors, v3, 3, N);
        
        vector<int> ans;
        for(int i=0; i<queries.size(); i++)
        {
            if(queries[i][1] == 1) ans.push_back(v1[queries[i][0]]);
            else if(queries[i][1] == 2) ans.push_back(v2[queries[i][0]]);
            else ans.push_back(v3[queries[i][0]]);
        }
        
        return ans;
    }
};

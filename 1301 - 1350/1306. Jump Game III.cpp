class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
        if(arr[start] == 0) return true;
        
        int N = arr.size();
        vector<int> visited(N, 0);
        queue<int> Q;
        Q.push(start);
        
        while(!Q.empty())
        {
            int idx = Q.front();
            visited[idx] = 1;
            
            int t1 = idx + arr[idx];
            int t2 = idx - arr[idx];
         
            if(arr[idx] == 0) return true;
            
            if(t1 < N && visited[t1] == 0) Q.push(t1);
            if(t2 > -1 && visited[t2] == 0) Q.push(t2);
            
            Q.pop();
        }
        
        return false;
    }
};

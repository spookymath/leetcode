/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> v;
        
        if(root == NULL) return v;
        
        queue<Node*> Q;
        Q.push(root);
        
        while(!Q.empty())
        {
            vector<int> u;
            int t = Q.size();
            for(int i=0; i<t; i++)
            {
                Node* tmp = Q.front();
                u.push_back(tmp->val);
                
                for(int j=0; j<tmp->children.size(); j++)
                    Q.push(tmp->children[j]);
                
                Q.pop();
            }
            v.push_back(u);
            u.clear();
        }
        return v;
    }
};

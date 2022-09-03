/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> v;
        if(root == NULL) return v;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty())
        {
            vector<int> temp;
            int sz = Q.size();
            for(int i=0; i<sz; i++)
            {
                if(Q.front()->left != NULL) Q.push(Q.front()->left);
                if(Q.front()->right != NULL) Q.push(Q.front()->right);
                temp.push_back(Q.front()->val);
                Q.pop();
            }
            v.push_back(temp);
        }
        
        return v;
    }
};

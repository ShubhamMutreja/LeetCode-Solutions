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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if(root == NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> base;
            while(size--)
            {
                TreeNode *p = q.front(); q.pop();
                
                base.push_back(p->val);
                if(p->left  != NULL) q.push(p->left);
                if(p->right  != NULL) q.push(p->right);
            }
            ans.push_back(base);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

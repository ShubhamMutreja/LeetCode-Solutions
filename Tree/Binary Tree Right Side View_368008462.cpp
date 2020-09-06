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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(q.size() != 0)
        {
            int size = q.size();
            TreeNode *rev = NULL;
            while(size-- > 0)
            {
                TreeNode *p = q.front();
                q.pop();
                
                if(p->left != NULL)
                {
                    q.push(p->left);
                }
                    
                if(p->right != NULL)
                {
                    q.push(p->right);
                }
                rev = p;
            }
            v.push_back(rev->val);
        }
        return v;
    }
};

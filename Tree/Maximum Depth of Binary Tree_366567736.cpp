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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode *r = q.front(); q.pop();
                if(r->left != NULL) q.push(r->left);
                if(r->right != NULL) q.push(r->right);
            }
            lvl++;
        }
        return lvl;
    }
    
};

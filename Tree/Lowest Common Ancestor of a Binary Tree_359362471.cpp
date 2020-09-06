/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *lca = NULL;
    bool fun(TreeNode *root,int p, int q)
    {
        if(root == NULL)
        {
            return false;
        }
        bool selffound = root->val == p || root->val == q;
        
        bool leftfound = fun(root->left,p,q);
        bool rightfound = fun(root->right,p,q);
        if((selffound && rightfound) || (rightfound && leftfound) || (leftfound && selffound))
            lca = root;
        return selffound||leftfound||rightfound;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool k = fun(root,p->val,q->val);
            return lca;
    }
};

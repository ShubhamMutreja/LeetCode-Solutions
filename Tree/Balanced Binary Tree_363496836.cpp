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
class Bal
{
    public:
    bool isBal = false;
    int height = -1;
    
};
class Solution {
public:
    Bal fun(TreeNode *root)
    {
        if(root == NULL)
        {
            Bal base;
            base.isBal = true;
            return base;
        }
    
        Bal l = fun(root->left);
        Bal r = fun(root->right);
        Bal ans;
        if(l.isBal && r.isBal && abs(l.height - r.height)<2)
        {
            ans.isBal = true;
        }
        ans.height = max(l.height,r.height) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        Bal p = fun(root);
        return p.isBal;
    }
};

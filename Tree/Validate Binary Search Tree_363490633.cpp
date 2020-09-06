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
typedef long long int ll;
class ans
{
    public:
    bool isBST = false;
    ll max_ele = -1e12;
    ll min_ele = 1e12;
};
class Solution {
public:
    ans f(TreeNode *p)
    {
        if(p == NULL)
        {
            ans base;
            base.isBST = true;
            return base;
        }
        
        ans l = f(p->left);
        ans r =f(p->right);
        
        ans ret;
        if(l.isBST && r.isBST && l.max_ele < p->val && r.min_ele > p->val)
        {
            ret.isBST = true;
        }
        ret.max_ele = max(max(l.max_ele,r.max_ele),(ll)p->val);
        ret.min_ele = min(min(l.min_ele,r.min_ele),(ll)p->val);
        
        return ret;
    }
    bool isValidBST(TreeNode* root) {
        ans p = f(root);
        return p.isBST;
    }
};

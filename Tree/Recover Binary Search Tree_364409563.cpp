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
    TreeNode *a=NULL,*b=NULL,*prev=NULL;
    bool fun(TreeNode *root)
    {
        if(root == NULL)
            return false;
        if(fun(root->left))
            return true;
        if(prev != NULL && prev->val > root->val)
        {
            b = root;
            if(a==NULL)
                a = prev;
            else
                return true;
        }
        prev = root;
        if(fun(root->right))
            return true;
        
        return false;
    }
    void recoverTree(TreeNode * root)
{
    fun(root);
    if(a!=NULL)
    {
        swap(a->val,b->val);
    }
}
};

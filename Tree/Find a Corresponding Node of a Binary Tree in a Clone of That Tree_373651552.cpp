class Solution {
public:
    TreeNode* recur(TreeNode* root,TreeNode* t)
    {
        if(root == NULL)
            return NULL;
        if(root->val == t->val)
            return root;
        TreeNode* l = recur(root->left,t);
        TreeNode* r = recur(root->right,t);
        if(l != NULL && l->val == t->val)
            return l;
        if(r != NULL && r->val == t->val)
            return r;
        return NULL;
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return recur(cloned,target);
    }
};

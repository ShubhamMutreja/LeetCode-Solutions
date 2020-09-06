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
    int solve(TreeNode* root,int &res)
    {
        if(root == NULL) return 0;
        
        int r = solve(root->right,res);
        int l = solve(root->left,res);
        
        int temp = max(max(l,r)+root->val , root->val);
        int ans = max(temp, root->val + l+r);
        res = max(ans,res);
        
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        int res=INT_MIN;
        int t = solve(root,res);
        return res;
    }
};

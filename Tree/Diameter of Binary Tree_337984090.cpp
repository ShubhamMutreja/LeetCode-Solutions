int solve(TreeNode *node,int &res)
{
    if(node == NULL)
    {
        return 0;
    }
    int r = solve(node->right,res);
    int l = solve(node->left,res);
    
    int temp = max(l,r)+1;
    int ans = max(temp,1+r+l);
    res = max(ans,res);
    
    return temp;
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
    if(root == NULL) 
    {
        return 0;
    }
    int res = INT_MIN;
    int t = solve(root,res);
    return res-1;
    }
};

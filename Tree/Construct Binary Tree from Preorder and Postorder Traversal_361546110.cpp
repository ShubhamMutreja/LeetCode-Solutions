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
    TreeNode* fun(vector<int>& pre, vector<int>& post,int psi,int pei,int ppsi, int ppei)
    {
        if(psi>pei)
        {
            return NULL;
        }
        if(pei==psi)
        {
            return new TreeNode(pre[psi]);
        }
        TreeNode* node = new TreeNode(pre[psi]);
        int idx=ppsi;
        while(post[idx] != pre[psi+1])
        {
            idx++;
        }
        int tel = idx-ppsi+1;
        node->left = fun(pre,post,psi+1,psi+tel,ppsi,idx);
        node->right = fun(pre,post,psi+tel+1,pei,idx+1,ppei-1);
        
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        int n = pre.size();
        return fun(pre,post,0,n-1,0,n-1);
    }
};

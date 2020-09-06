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
    TreeNode* fun(vector<int>& pre, vector<int>& in,int isi,int iei,int psi,int pei)
    {
        if(psi>pei)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(pre[psi]);
        int idx=isi;
        while(pre[psi] != in[idx])
        {
            idx++;
        }
        int tel = idx-isi;
        node->left = fun(pre,in,isi,idx-1,psi+1,psi+tel);
        node->right = fun(pre,in,idx+1,iei,psi+tel+1,pei);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return fun(preorder,inorder,0,n-1,0,n-1);
    }
};

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
    TreeNode* fun(vector<int>& post, vector<int>& in,int isi,int iei,int psi,int pei)
    {
        if(psi>pei)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(post[pei]);
        int idx=isi;
        while(post[pei] != in[idx])
        {
            idx++;
        }
        int tel = idx-isi;
        node->left = fun(post,in,isi,idx-1,psi,psi+tel-1);
        node->right = fun(post,in,idx+1,iei,psi+tel,pei-1);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return fun(postorder,inorder,0,n-1,0,n-1);
    }
};

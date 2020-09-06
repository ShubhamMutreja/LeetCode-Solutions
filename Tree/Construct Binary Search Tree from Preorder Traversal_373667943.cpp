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
    TreeNode* bst(vector<int>& preorder,int start,int end)
{
if((start>end)||(preorder.size()==0))
return NULL;

TreeNode *root= new TreeNode(preorder[start]);

int i;
for( i=start;i<=end;i++)
{
    if(preorder[i]>root->val)//get the i element for while preoder[i]>root
        break;
}
root->left=bst(preorder,start+1,i-1);//dividing smaller element in left sub tree
root->right=bst(preorder,i,end);//dividing larger element in right sub tree
return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0)
            return NULL;
        return bst(preorder,0,preorder.size()-1);
        
    }
};

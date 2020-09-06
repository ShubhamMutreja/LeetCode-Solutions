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
    void leftmost(TreeNode *node,stack<TreeNode*> &st)
    {
        while(node!=NULL)
        {
            st.push(node);
            node = node->left;
        }
    }
    int kthSmallest(TreeNode *root,int k)
    {
        stack<TreeNode*> st;
        leftmost(root,st);

        int ans= -1;
        while(k--)
        {
            TreeNode *rnode = st.top();
            st.pop();
            leftmost(rnode->right,st);
            ans = rnode->val;
        } 
        return ans;
    }
};

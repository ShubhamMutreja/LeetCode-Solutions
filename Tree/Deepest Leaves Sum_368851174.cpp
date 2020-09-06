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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum;
        while(q.size() != 0)
        {
            int size = q.size();
            sum = 0;
            while(size--)
            {
                TreeNode *rvtx = q.front();
                q.pop();
                sum += rvtx->val;
                if(rvtx->left != NULL)
                    q.push(rvtx->left);
                if(rvtx->right != NULL)
                    q.push(rvtx->right);
            }
        }
        return sum;
    }
};

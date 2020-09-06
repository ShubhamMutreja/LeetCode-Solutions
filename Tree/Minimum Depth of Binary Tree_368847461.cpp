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
    int minDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        while(q.size() != 0)
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* rvtx = q.front(); q.pop();
                if(rvtx->left != NULL)
                {
                    q.push(rvtx->left);
                }
                if(rvtx->right != NULL)
                {
                    q.push(rvtx->right);
                }
                if(rvtx->left == NULL && rvtx->right == NULL)
                {
                    return level;
                }
            }
            level++;
        }
        return level;
    }
};

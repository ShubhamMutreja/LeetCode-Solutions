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
    vector<vector<int>> ans;
    vector<int> res;
    void fun(TreeNode* root,int sum)
    {
        if(root == NULL)
        {
            return;
        }
        //sum = sum ;
        
        if(root->left == NULL && root->right == NULL && sum- root->val == 0)
        {
            vector<int> temp(res);
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        res.push_back(root->val);
        
        fun(root->left,sum- root->val);
        fun(root->right,sum- root->val);
        
        res.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        fun(root,sum);
        return ans;
    }
};

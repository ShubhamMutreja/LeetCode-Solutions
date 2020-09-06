class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return {};
        if(root->left == NULL && root->right == NULL)
        {
            vector<string> base;
            base.push_back(to_string(root->val));
            return base;
        }
        vector<string> ans;
        vector<string> l = binaryTreePaths(root->left);
        vector<string> r = binaryTreePaths(root->right);
        
        for(auto &s : l)
        {
            ans.push_back(to_string(root->val) + "->" + s);
        }
        for(auto &s : r)
        {
            ans.push_back(to_string(root->val) +"->" + s);
        }
        return ans;
    }
};
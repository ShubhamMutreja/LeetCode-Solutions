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
    void print(vector<int> &v)
{
    for (auto i: v) {
        std::cout << i << ' ';
    }

    std::cout << '\n';
}
    vector<int> dfs(TreeNode *p)
    {
        if(p==NULL)
            return {};
        if(p->left == NULL && p->right == NULL)
            return {p->val};
        vector<int> l = dfs(p->left);
        vector<int> r = dfs(p->right);
        l.insert(l.end(),r.begin(),r.end());
        return l;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> f = dfs(root1);
        vector<int> s = dfs(root2);
        print(f);
        print(s);
        if(f.size() != s.size())
            return false;
        for(int i=0;i<f.size();i++)
        {
            if(f[i] != s[i])
                return false;
        }
        return true;
    }
};

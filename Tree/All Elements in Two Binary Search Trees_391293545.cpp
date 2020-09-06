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
    vector<int> l,r;
    void level_l(TreeNode* p)
    {
        if(p == NULL)
            return;
        
        level_l(p->left);
        l.push_back(p->val);
        level_l(p->right);
    }
    void level_r(TreeNode* p)
    {
        if(p == NULL)
            return;
        
        level_r(p->left);
        r.push_back(p->val);
        level_r(p->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        level_l(root1);
        level_r(root2);
        if(l.size() == 0)
            return r;
        if(r.size() == 0)
            return l;
        int i=0,j=0;
        while(i < l.size() && j < r.size())
        {
            if(l[i] < r[j])
            {
                ans.push_back(l[i]);
                i++;
            }
            else
            {
                ans.push_back(r[j]);
                j++;
            }
        }
        while(i < l.size())
            ans.push_back(l[i++]);
        while(j < r.size())
            ans.push_back(r[j++]);
        return ans;
        
    }
};

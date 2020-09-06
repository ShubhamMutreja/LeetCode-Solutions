// 0 : isBST
// 1 : min_ele
// 2 : max_ele
// 3 : sum;
// 4 : max_sum
class Solution {
public:
    vector<int> fun(TreeNode * root)
    {
        if(root == NULL)
        {
            return {1,(int)1e8,(int)-1e8,0,0};
        }
        vector<int> la = fun(root->left);
        vector<int> ra = fun(root->right);
        
        bool isBST = la[0]==1 && ra[0]==1 && la[2] < root->val && root->val < ra[1];
        int sum = la[3] + ra[3] + root->val;
        int max_sum = 0;
        if(isBST==1)
        {
            max_sum = max(sum,max(la[4],ra[4]));
        }
        else
        {
            max_sum = max(la[4],ra[4]);
        }
        return {isBST?1:0,min(root->val,min(ra[1],la[1])),max(root->val,max(ra[2],la[2])),sum,max_sum};
        
    }
    int maxSumBST(TreeNode* root) {
     return fun(root)[4];
    }
};

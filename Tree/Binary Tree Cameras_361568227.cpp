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
    int cam = 0;
    int minCamTree_(TreeNode *root)
    {
        if(root ==NULL)
        {
            return 1;
        }
        int lans = minCamTree_(root->left);
        int rans = minCamTree_(root->right);
        

        if(lans == -1 || rans == -1)
        {
            cam++;
            return 0;
        }
        else if(lans ==0 || rans == 0)
        {
            return 1;
        }
        return -1;


    }
    int minCameraCover(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        if(minCamTree_(root) == -1)
        {
            cam++;
        };
        return cam;
        
    }
};

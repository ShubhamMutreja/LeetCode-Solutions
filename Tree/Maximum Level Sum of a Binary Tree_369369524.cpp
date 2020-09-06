
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxx = -1e8;
        int lvl = 0; int level = 0;
        while(q.size() != 0)
        {
            int size = q.size();
            
            int sum = 0;
            while(size--)
            {
                TreeNode * p = q.front(); q.pop();
                sum += p->val;
                
                if(p->left != NULL) 
                    q.push(p->left);
                if(p->right != NULL) 
                    q.push(p->right);
            }
            lvl++;
            if(sum > maxx)
            {
                maxx = sum;
                level = lvl;
            }
             
        }
        cout<<maxx;
        return level;
    }
};

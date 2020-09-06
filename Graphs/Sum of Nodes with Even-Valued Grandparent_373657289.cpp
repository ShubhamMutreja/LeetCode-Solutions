class Solution {    
private:    
    int sum;
    void dfs(TreeNode* root, vector<int> V){
        if(root == nullptr)
            return;
            
        if(V[0] %2 == 0){
            sum += root->val;
        }
        
        V[0] = V[1];
        V[1] = root->val;
        
        dfs(root->left, V);
        dfs(root->right,V);
    }
public:

    int sumEvenGrandparent(TreeNode* root) {
        
        sum = 0;  
        
        vector<int> V(2,1); 
        
        dfs(root,V); 
        
        return sum;
    }
};

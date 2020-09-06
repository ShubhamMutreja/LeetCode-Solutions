class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL){
            return root;
        }
        queue<Node*> dp;
        dp.push(root);
        
        while(!dp.empty())
        {
            int size = dp.size();
            while(size--)
            {
                Node* current = dp.front();
                dp.pop();
                
                if (current->left){
                    dp.push(current->left);
                }
                if (current->right){
                    dp.push(current->right);
                }
                
                if (size != 0){
                    current->next = dp.front();
                }
            }
        }
        
        Node* current = root;
        while(current->right != NULL){
            current->next = NULL;
            current = current->right;
        }
        
        return root;
    }
};

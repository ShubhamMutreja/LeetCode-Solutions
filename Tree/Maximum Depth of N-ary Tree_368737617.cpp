/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        queue<Node*> q;
        q.push(root);
        int level = 0;
        
        while(q.size() != 0)
        {
            int size = q.size();
            while(size--)
            {
                Node *rvtx = q.front(); q.pop();
                
                if(rvtx->children.size() != 0)
                {
                    for(auto e : rvtx->children)
                        q.push(e);
                }
            }
            level++;
        }
        return level;
    }
};

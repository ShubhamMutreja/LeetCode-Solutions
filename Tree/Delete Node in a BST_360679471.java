/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int maximum(TreeNode root)
    {
        TreeNode curr = root;
        while(curr.right != null)
        {
            curr = curr.right;
        }
        return curr.val;
    }
    public TreeNode deleteNode(TreeNode root, int key) 
    {
        if(root == null)
        {
            return null;
        }
        if(key < root.val)
        {
            root.left = deleteNode(root.left,key);
        }
        else if(key > root.val)
        {
            root.right = deleteNode(root.right,key);
        }
        else if(root.val == key)
        {
            if(root.left == null || root.right == null)
            {
                return root.left != null? root.left : root.right;
            }
        
        int maxele = maximum(root.left);
        root.val = maxele;
        root.left = deleteNode(root.left,maxele);
        }
        return root;
    }
}

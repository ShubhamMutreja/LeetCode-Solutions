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
    int moves = 0;
    public int dfs(TreeNode p)
    {
        if(p == null)
            return 0;
        
        int left = dfs(p.left);
        int right = dfs(p.right);
        
        moves += Math.abs(left) + Math.abs(right);
        return p.val + left + right - 1;
    }
    public int distributeCoins(TreeNode root) {
        
        dfs(root);
        return moves;
    }
}
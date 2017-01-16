/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class SortedArrayToBST {
    
    public TreeNode sortedArrayToBST(int[] num) {
        
        if (num.length == 0)
            return null;
        
        int end = num.length - 1;
        
        return sortedArrayToBST(0,end,num);
        
    }
    
    private TreeNode sortedArrayToBST(int start, int end, int [] num)
    {
        if (end < start)
            return null;
        
        int mid = (start + end)/2;
        TreeNode root = new TreeNode(num[mid]);
        root.left = sortedArrayToBST(start,mid-1,num);
        root.right = sortedArrayToBST(mid+1,end,num);
        return root;
        
    }
}
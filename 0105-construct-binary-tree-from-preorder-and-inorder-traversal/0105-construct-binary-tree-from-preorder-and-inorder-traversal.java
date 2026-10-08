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
    public int  getIndex(int []inorder,int val){
        for(int i=0;i<inorder.length;i++){
            if(inorder[i]==val)return i;
        }
        return -1;
    }
    public TreeNode f(int []preorder,int []inorder,int [] index,int s,int e){

        if(s>e || index[0]==preorder.length) return null;

        TreeNode root=new TreeNode(preorder[index[0]]);
        int pos=getIndex(inorder,preorder[index[0]]);
        index[0]++;

        root.left = f(preorder,inorder,index,s,pos-1);
        root.right = f(preorder,inorder,index,pos+1,e);
        return root;

    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        
        int n=preorder.length;
        return f(preorder,inorder,new int []{0},0,n-1);

    }
}
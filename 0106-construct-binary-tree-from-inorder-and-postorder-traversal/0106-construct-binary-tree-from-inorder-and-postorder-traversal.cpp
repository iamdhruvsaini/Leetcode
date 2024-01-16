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
    int position(vector<int>&inorder,int t){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==t)return i;
        }
        return -1;
    }
    TreeNode * solve(vector<int>& inorder, vector<int>& postorder,int s,int e,int &i){
        if(i<0 || s>e)return NULL;
        
        int num=postorder[i--];
        TreeNode * root=new TreeNode(num);
        int pos=position(inorder,num);
        
        root->right=solve(inorder,postorder,pos+1,e,i);
        root->left=solve(inorder,postorder,s,pos-1,i);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int i=n-1;
        return solve(inorder,postorder,0,n-1,i);
        
    }
};
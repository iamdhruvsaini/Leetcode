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
    
    int position(vector<int>& inorder,int val){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
        
    }
    TreeNode * solve(vector<int>& preorder, vector<int>& inorder,int inorderstart,int inorderend,int &index){
        
        if(index>=preorder.size() || inorderstart>inorderend){
            return NULL;
        }
        
        TreeNode * root=new TreeNode(preorder[index]);
        int pos=position(inorder,preorder[index]);
        
        index++;
        root->left=solve(preorder,inorder,inorderstart,pos-1,index);
        root->right=solve(preorder,inorder,pos+1,inorderend,index);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inorderstart=0;
        int inorderend=inorder.size()-1;
        int index=0;
        return solve(preorder,inorder,inorderstart,inorderend,index);
        
        
        
    }
};
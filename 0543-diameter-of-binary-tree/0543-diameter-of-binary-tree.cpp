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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }

        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);

        int op1=left.first;
        int op2=right.first;
        int op3=op1+op2+1;
        int maxDepth=max(op1,max(op2,op3));

        int maxi=max(maxDepth,max(left.second,right.second));


        return {max(op1,op2)+1 , maxi};


    }
    int diameterOfBinaryTree(TreeNode* root) {

        return solve(root).second-1;
        
    }
};
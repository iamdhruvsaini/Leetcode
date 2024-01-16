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
    bool chk(TreeNode * root1,TreeNode * root2){
        if(root1==NULL && root2==NULL)return true;
        if(root1==NULL && root2!=NULL)return false;
        if(root1!=NULL && root2==NULL)return false;
        if(root1->val != root2->val)return false;
        
        bool r=chk(root1->left,root2->right);
        if(r==false)return 0;
        bool l=chk(root1->right,root2->left);
        if(l==0)return 0;
        if( root1->val == root2->val && r && l)return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return chk(root->left,root->right);
    }
};
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
    bool solve(TreeNode* root,long long  maxi,long long mini){
        if(root==NULL)return 1;

        if(root->val>mini && root->val <maxi){
            bool l=solve(root->left,root->val,mini);
            bool r=solve(root->right,maxi,root->val);

            return l && r;
        }
        else{
            return 0;

        }

    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MAX,LLONG_MIN);
        
    }
};
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
    void flatten(TreeNode* root) {

        if(root==NULL)return ;
        TreeNode * head=root;
        TreeNode * ans=head;

        while(head!=NULL){
            if(head->left==NULL){
                head=head->right;
            }
            else{
                TreeNode * temp=head->left;
                while(temp->right!=NULL && temp->right!=NULL){
                    temp=temp->right;
                }

                if(temp->right==NULL){
                  temp->right=head->right;
                  TreeNode * leftNode=head->left;
                  head->right=leftNode;
                  head->left=NULL;
                  head=leftNode;
                }
                else{
                    head=temp->right;
                }
            }
        }


    }
};
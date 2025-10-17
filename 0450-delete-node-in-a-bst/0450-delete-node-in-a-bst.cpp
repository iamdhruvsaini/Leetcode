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
    TreeNode * maxValue(TreeNode * root){
    
      // Assuming root is not NULL before calling this function
        TreeNode * current = root;
        while(current->right != NULL){ // Correct: Traverse right until the end
            current = current->right;
        }
        return current;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return root;

        if(root->val==key){

            //case 1 : leaf node
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            // case 2: single child
            else if(root->left!=NULL && root->right==NULL){
               TreeNode * temp=root->left;
                delete root;
                return temp;
            }
            else if(root->right!=NULL && root->left==NULL){
               TreeNode * temp=root->right;
                delete root;
                return temp;
            }

            // 2 childs

            else{
                int mini=maxValue(root->left)->val;
                root->val=mini;
                root->left=deleteNode(root->left,mini);
                return root;
            }

        }

        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else{
            root->right=deleteNode(root->right,key);
        }
        
        return root;
    }
};
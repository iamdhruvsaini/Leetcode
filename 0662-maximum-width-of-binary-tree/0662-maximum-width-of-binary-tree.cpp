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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* ,int>>q;
        q.push({root,0});

        int width=INT_MIN;
        while(!q.empty()){

            int size=q.size();
            int mmin=q.front().second;
            int left,right;
            for(int i=0;i<size;i++){

                pair<TreeNode* ,int>p=q.front();
                q.pop();
                TreeNode * curr=p.first;
                int id=p.second-mmin;

                if(curr->left){
                    q.push({curr->left,2LL*id+1});
                }

                if(curr->right){
                    q.push({curr->right,2LL *id+2});
                }

                if(i==0){
                    left=id;
                }
                if(i==size-1){
                    right=id;
                }
            }
            width=max(width,right-left+1);
        }
        return width;
        
    }
};
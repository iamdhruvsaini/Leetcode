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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        
        vector<vector<int>> ans;
        if(root==NULL)return ans;

        map<int,map<int,vector<int>>>mp;

        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> p=q.front();
            q.pop();

            TreeNode* node=p.first;
            pair<int,int> dist=p.second;
            mp[dist.first][dist.second].push_back(node->val);
            if(node->left){
                q.push({node->left,{dist.first-1,dist.second+1}});
            }
            if(node->right){
                q.push({node->right,{dist.first+1,dist.second+1}});
            }
            
        }

        for (auto const& [hd, level_map] : mp) {
            vector<int> col;
            for (auto const& [level, node_vals] : level_map) {
                // Nodes at the same hd and level must be sorted by value.
                vector<int> sorted_vals = node_vals;
                sort(sorted_vals.begin(), sorted_vals.end());
                col.insert(col.end(), sorted_vals.begin(), sorted_vals.end());
            }
            ans.push_back(col);
        }

        return ans;
        
    }
};
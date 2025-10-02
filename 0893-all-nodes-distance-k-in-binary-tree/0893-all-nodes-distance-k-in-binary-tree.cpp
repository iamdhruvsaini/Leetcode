class Solution {
public:
    void getMapping(TreeNode * root,unordered_map<TreeNode *, TreeNode *>&mp){
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * temp=q.front();
            q.pop();
            if(temp->left){
                mp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                mp[temp->right]=temp;
                q.push(temp->right);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    
        unordered_map<TreeNode *, TreeNode *>mp;
        getMapping(root,mp);
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode * ,bool>visited;
        visited[target]=1;

        while(!q.empty()){
            int size=q.size();
            if(k==0)break;
            k--;
            for(int i=0;i<size;i++){
                TreeNode * front=q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=1;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=1;
                }
                if(mp[front] && !visited[mp[front]]){
                    q.push(mp[front]);
                    visited[mp[front]]=1;
                }
            }
        }

        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};
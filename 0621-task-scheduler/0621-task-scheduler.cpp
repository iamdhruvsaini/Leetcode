class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;

        for(auto i:tasks){
            mp[i]++;
        }       
        priority_queue<int>q;
        for(auto i: mp){
            q.push(i.second);
        }


        int ans=0;
        while(!q.empty()){
            vector<int>temp;
            int top=q.top();
            temp.push_back(top-1);
            q.pop();
            for(int i=0;i<n;i++){
                if(!q.empty()){
                    int p=q.top();
                    temp.push_back(p-1);
                    q.pop();
                }
            }

            for(int i=0;i<temp.size();i++){
                if(temp[i]>0) q.push(temp[i]);
            }
            if(q.empty()) ans+=temp.size();
            else ans+=n+1;
        }

        return ans;
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>arr(n+1,0);
        unordered_map<int,int>mp;
        for(int i=0;i<trust.size();i++){
            int b=trust[i][1];
            arr[b]++;
            mp[trust[i][0]]=1;
        }

        for(int i=1;i<=n;i++){
            // cout<<arr[i]<<" ";
            if(arr[i]==n-1){
                if(mp.find(i)==mp.end())return i;
            };
        }
        return -1;

        
    }
};
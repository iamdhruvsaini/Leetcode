class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int ans=0;
        for(auto i:mp){
            int cnt=i.second;
            if(cnt<=1)return -1;
            else if(cnt%3==0)ans+=cnt/3;
            else if(cnt%3==1)ans=ans+1+cnt/3;
            else if(cnt%3==2)ans=ans+1+cnt/3;
        }
        return ans;
        
    }
};
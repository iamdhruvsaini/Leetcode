class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> prefix(n,0);
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            prefix[l]++;
            if(r+1 < n)prefix[r+1]--;
        }


        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+prefix[i];
        }
        for(int i=0;i<n;i++){
            if(prefix[i] < nums[i] )return false;
        }
        return true;



    }
};
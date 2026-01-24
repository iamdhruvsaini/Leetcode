class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prev=1;
        int suff=1;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(prev ==0)prev=1;
            if(suff==0)suff=1;

            prev=prev*nums[n-i-1];
            suff=suff*nums[i];

            maxi=max({maxi,prev,suff});
        }

        return maxi;
    }
};
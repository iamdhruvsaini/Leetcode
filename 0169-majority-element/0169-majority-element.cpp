class Solution {
public:
    int majorityElement(vector<int>& nums) {
       // Moores Voting Algorithm
       int cnt=0;
       int ans=-1;
       for(int i=0;i<nums.size();i++){
        if(cnt==0){
            cnt=1;
            ans=nums[i];
        }else if(nums[i]==ans){
            cnt++;
        }else{
            cnt--;
        }
       }
       return ans;
    }
};
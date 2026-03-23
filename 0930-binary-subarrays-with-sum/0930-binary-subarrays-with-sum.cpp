class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        function<int(int)>f=[&](int g){
            if(g< 0) return 0;
            int i=0,j=0;
            int n=nums.size();
            int sum=0;
            int cnt=0;
            while(j<n){
                sum+=nums[j];
                while(sum>g){
                    sum-=nums[i];
                    i++;
                }
                cnt+=j-i+1;
                j++;
            }
            return cnt;

        };
   
        return f(goal)-f(goal-1);

    }
};
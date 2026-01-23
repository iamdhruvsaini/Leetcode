class Solution {
public:
    int minimumPairRemoval(vector<int>& temp) {     

        vector<long long> nums;
        for(int i=0;i<temp.size();i++)nums.push_back(temp[i]);
        int n=nums.size();
        set<pair<long long,int>>st;
        int badPairs=0;
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1]){
                badPairs++;
            }
            st.insert({nums[i]+nums[i+1],i});
        }

        vector<int>prev(n,0),next(n,0);
        for(int i=0;i<n;i++){
            prev[i]=i-1;
            next[i]=i+1;
        }
        int operations=0;

        while(badPairs){
            // find the min sum  
            auto it=st.begin();
           // pop it
            long long sum=it->first;  // CHANGE 1: Changed from int to long long
            int first=it->second;
            int second=next[first];
            st.erase(it);

            int first_prev=prev[first];
            int second_next=next[second];
            

            // now check for the badpair
            if(nums[first]>nums[second]){
                // as we popped so 1 bad pair got removed
                badPairs--;
            }

            // now update the minsum 
            //               a, b
            //  first_prev , a, b, second_next

            if(first_prev >=0){
                // CHANGE 2: Fixed logic - check transitions between good and bad pairs
                // Was bad (first_prev > first), becomes good (first_prev <= sum)
                if(nums[first_prev] > nums[first] && nums[first_prev] <= sum ){
                    badPairs--;
                }
                // Was good (first_prev <= first), becomes bad (first_prev > sum)
                else if(nums[first_prev] <= nums[first] && nums[first_prev] > sum ){
                    badPairs++;
                }

                // remove the corresponding sum
                st.erase({nums[first_prev]+nums[first] , first_prev});
                // add the corresponding sum
                st.insert({nums[first_prev]+sum, first_prev});
            }
            // similarly check for the b and second-next

            if(second_next < n){
                 // CHANGE 3: Fixed logic - check transitions between good and bad pairs
                 // Was good (second_next >= second), becomes bad (second_next < sum)
                 if(nums[second_next] >= nums[second] && nums[second_next] < sum){
                    badPairs++;
                 }
                 // Was bad (second_next < second), becomes good (second_next >= sum)
                 else if(nums[second_next] < nums[second] && nums[second_next] >= sum){
                    badPairs--;
                 }
                // now first remove the earlier sum
                st.erase({nums[second_next]+nums[second] , second});
                // add the new one now
                st.insert({nums[second_next]+sum,first});

                prev[second_next]=first;
            }

            next[first]=second_next;
            nums[first]=sum;  // CHANGE 4: Use sum directly instead of recalculating

            operations++;
        }

        return operations;
    }
};
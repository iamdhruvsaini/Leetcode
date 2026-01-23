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
            long long sum=it->first;  // CHANGE 1: Changed from int to long long to prevent overflow
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
                // CHANGE 2: Fixed logic - check if OLD pair (first_prev, first) was bad
                if(nums[first_prev] > nums[first]){
                    badPairs--;  // Old pair was bad, now it's gone
                }
                // CHANGE 3: Fixed logic - check if NEW pair (first_prev, sum) is bad
                if(nums[first_prev] > sum){
                    badPairs++;  // New pair is bad
                }

                // remove the corresponding sum
                st.erase({nums[first_prev]+nums[first] , first_prev});
                // add the corresponding sum
                st.insert({nums[first_prev]+sum, first_prev});
            }
            // similarly check for the b and second-next

            if(second_next < n){
                 // CHANGE 4: Fixed logic - check if OLD pair (second, second_next) was bad
                 if(nums[second] > nums[second_next]){
                    badPairs--;  // Old pair was bad, now it's gone
                 }
                 // CHANGE 5: Fixed logic - check if NEW pair (sum, second_next) is bad
                 if(sum > nums[second_next]){
                    badPairs++;  // New pair is bad
                 }
                
                // now first remove the earlier sum
                st.erase({nums[second_next]+nums[second] , second});
                // add the new one now
                st.insert({nums[second_next]+sum,first});

                prev[second_next]=first;
            }

            // CHANGE 6: Added this line to maintain linked list integrity
            if(first_prev >= 0) {
                next[first_prev] = first;
            }

            next[first]=second_next;
            nums[first]=sum;  // CHANGE 7: Use sum directly instead of recalculating

            operations++;
        }

        return operations;
    }
};
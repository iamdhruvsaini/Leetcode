class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0,e=nums.size()-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            bool left=false;
            bool right=false;
            if(mid-1>=s){
                left=nums[mid]==nums[mid-1];
            }
            if(mid+1<=e){
                right=nums[mid]==nums[mid+1];
            }
            if(left==false && right==false){
                return nums[mid];
            }

            else if(left){
                if((mid-1-s)%2==0){
                    s=mid+1;
                }
                else{
                    e=mid-2;
                }
            }
            else if(right){
                 if((e-mid+1)%2==0){
                    //yahan pr nhi lie krta hai
                    e=mid-1;
                }
                else{
                    s=mid+2;
                }

            }
        }
        return -1;
    }
};
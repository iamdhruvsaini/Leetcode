class Solution {
public:
    void insert(vector<int>&arr,int num,int pos,int &size){
        int n=arr.size();
        int i=0;
        while(i<pos){
            i++;
        }
        int prev=arr[i];
        for(int j=pos+1;j<n;j++){
            int curr=arr[j];
            arr[j]=prev;
            prev=curr;
        }
        arr[pos]=num;
        size++;
    }
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {

        vector<int>ans(nums.size(),0);

        int size=0;
        for(int i=0;i<nums.size();i++){
            int element=nums[i];
            int pos=index[i];
            insert(ans,element,pos,size);
        }
        return ans;

    }
};
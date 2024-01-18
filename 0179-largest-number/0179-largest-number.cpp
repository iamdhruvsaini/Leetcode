class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>str;
        for(int i=0;i<nums.size();i++){
            string t=to_string(nums[i]);
            str.push_back(t);
        }
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                string temp1=str[i]+str[j];
                string temp2=str[j]+str[i];
                if(temp2>temp1){
                    swap(str[i],str[j]);
                }
            }
        }
        string ans;
        for(int i=0;i<nums.size();i++){
            ans+=str[i];
        }
        bool flag=true;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0')flag=false;
        }
        if(flag)return "0";
        return ans;
    }
};
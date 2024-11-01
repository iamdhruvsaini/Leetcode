class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3)return s;

        string ans="";
        if(s[1]==s[2] && s[0]==s[1] ){
            ans+=s[0];
            ans+=s[2];
        }
        else{
            ans+=s[0];
            ans+=s[1];
            ans+=s[2];
        }

        int left=1;
        int right=3;
        while(right<s.size()){
            if(right>=s.size())break;
            if(s[left+1]==s[left+2] && s[left]==s[left+1] ){

            }
            else{
                ans+=s[right];

            }
           left++;
           right++;
        }
        return ans;
    }
};
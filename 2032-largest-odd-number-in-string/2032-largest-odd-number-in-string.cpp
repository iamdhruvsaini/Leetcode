class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1;i>=0;i--){
            int temp=num[i]-'0';
            if(temp&1){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};
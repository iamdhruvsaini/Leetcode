class Solution {
public:
    void solve(string &digits, vector<string>&phone, vector<string>&ans, string temp, int index ){
        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }

        int digit=digits[index]-'0';

        string keys=phone[digit];
        for(int i=0;i<keys.size();i++){
            // consider taking the key 
            temp.push_back(keys[i]);
            solve(digits,phone,ans,temp,index+1);
            temp.pop_back();

        }

        
    }

    vector<string> letterCombinations(string digits) {
        if(digits=="")return  {};
        vector<string>phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string temp="";
        solve(digits,phone,ans,temp,0);

        return ans;

    }
};
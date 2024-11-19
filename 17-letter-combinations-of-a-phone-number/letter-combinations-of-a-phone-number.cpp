#define vs vector<string>
class Solution {
public:

    void solve(vs &temp,vs &ans,int n,string &possible,string digits){

        if(n>=digits.size()){

            ans.push_back(possible);
            return;
        }
        int number=digits[n] - '0';;
        for(int i=0;i<temp[number].size();i++){
            possible=possible+temp[number][i];
            solve(temp,ans,n+1,possible,digits);
            possible.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vs temp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vs ans;
        string possible="";
        solve(temp,ans,0,possible,digits);
        return ans;
    }
};
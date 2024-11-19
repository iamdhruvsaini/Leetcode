#define vs vector<string>

class Solution {
public:
    void solve(vs &ans, string &temp, string &s,int i){
        if(i>=s.size()){
            ans.push_back(temp);
            return;
        }

        if(isdigit(s[i])){
            temp+=s[i];
            solve(ans,temp,s,i+1);
            temp.pop_back();
            return;
        }       
        temp+=toupper(s[i]);
        solve(ans,temp,s,i+1);
        temp.pop_back();
        temp+=tolower(s[i]);
        solve(ans,temp,s,i+1);
        temp.pop_back();
    }
    vector<string> letterCasePermutation(string s) {
        vs ans;
        string temp;
        solve(ans,temp,s,0);
        return ans;
    }
};
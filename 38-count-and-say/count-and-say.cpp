class Solution {
public:
    void solve(int a,string &ans,int n){
        if(a>n)return;

        string temp="";
        int cnt=1;
        for(int i=1;i<ans.size();i++){
            if(ans[i]!=ans[i-1]){
                string ch=to_string(cnt);
                temp+=ch;
                temp+=ans[i-1];
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        string ch=to_string(cnt);
        temp+=ch;
        temp+=ans[ans.size()-1];
        ans=temp;

        solve(a+1,ans,n);

    }
    string countAndSay(int n) {
        string ans="1";
        solve(2,ans,n);
        return ans;
    }
};
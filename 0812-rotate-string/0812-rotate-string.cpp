class Solution {
public:
    void getLps(vector<int>&lps,string goal){
        int f=0;
        int s=1;
        while(s<goal.length()){
            if(goal[f]==goal[s]){
                lps[s]=f+1;
                s++;
                f++;
            }
            else{
                if(f!=0){
                    f=lps[f-1];
                }
                else{
                    s++;
                }
            }
        }
    }
    bool rotateString(string s, string goal) {
        s=s+s;
        if (goal.length() != s.length() / 2) return false;
        vector<int>lps(goal.size(),0);
        getLps(lps,goal);

        // now i am having the lps array

        int f=0;
        int st=0;
        while(f<s.size()){
            if(goal[st]==s[f]){
                st++;
                f++;
                if(st==goal.size())return 1;
            }

            else{
                if(st!=0){
                    st=lps[st-1];
                }
                else{
                    f++;
                }
            }
        }
        if(st==goal.size())return 1;
        return 0;

    }   
};
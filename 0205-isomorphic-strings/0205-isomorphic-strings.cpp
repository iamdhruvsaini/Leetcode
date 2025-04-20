class Solution {
public:
    bool isIsomorphic(string s, string t) {
                if(s.length()!= t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j] && t[i]!=t[j]){
                    return false;
                }
                if(s[i]!=s[j] && t[i]==t[j]){
                    return false;
                }
            }
        }
        return true;

    }
    
};
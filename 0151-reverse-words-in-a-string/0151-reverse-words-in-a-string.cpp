class Solution {
public:
    string formatString(string & s){
        int n=s.size();
        int i=0;
        string ans="";
        string temp="";
        // skip starting spaces
        while(i<n && s[i]==' '){
            i++;
        }


        while(i<n){
            if(s[i]==' '){
                temp+=" ";
                ans+=temp;
                temp="";
                while(s[i]==' ' && i<n){
                    i++;
                }

            }
            else{
                temp+=s[i++];
            }
        }
        if(temp!="")ans+=temp;

        return ans;
    }
    string reverseWords(string s) {
        s=formatString(s);

        // now reverse the words
        int last=0;
        string ans="";
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                temp+= ans!=""?" ":"";
                ans=temp+ans;
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        if(temp!=""){
            if(ans!=""){

                temp+=' ';
            }
            ans=temp+ans;
        }

        return ans;
       
    }
};
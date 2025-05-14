class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        int i=0,j=0;
        while(j<n){
            if(s[j]==' '){
                reverse(s.begin()+i,s.begin()+i+j-i);
                i=j+1;
                j++;
            }
            else{
                j++;
            }
        }
        reverse(s.begin()+i,s.begin()+i+j-i);
        // now remove extra spaces
        string ans="";
        i=0,j=n-1;
        while(s[i]==' '){
            i++;
        }
        while(s[j]==' '){
            j--;
        }
        bool flag=false;
        for(;i<=j;i++){
            if(s[i]==' ' && flag==false){
                flag=true;
                ans+=s[i];
            }
            else if(s[i]!=' '){
                ans+=s[i];
                flag=false;
            }

        }
        return ans;
    }
};
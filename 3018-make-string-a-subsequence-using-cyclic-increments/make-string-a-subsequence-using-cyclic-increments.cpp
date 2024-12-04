class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        int j=0;

        while(i<str1.size() && j< str2.size()){
            char ch=str1[i];
            char nxt=ch;
            if(ch=='z'){
                nxt='a';
            }
            else{
                nxt=nxt+1;
            }


            if(str2[j]==nxt || str2[j]==ch){
                j++;
            }
            i++;
        }

        if(j==str2.size())return true;
        return false;
        
    }
};
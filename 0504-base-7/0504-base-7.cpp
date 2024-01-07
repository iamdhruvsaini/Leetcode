class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)return "0";
        string temp="";
        bool isnegative=false;
        if(num<0){
            num=num*-1;
            isnegative=true;
        }
        
        while(num){
            int remainder=num%7;
            num=num/7;
            char ch='0'+remainder;
            temp=temp+ch;
        }
        if(isnegative)temp.push_back('-');
        reverse(temp.begin(),temp.end());
        
        return temp;
        
    }
};
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
       
        sort(vBars.begin(),vBars.end());
        sort(hBars.begin(),hBars.end());

        int vConsecutive=1;
        int maxVConsecutive=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1){
                vConsecutive++;
            }
            else{
                vConsecutive=1;
            }
            maxVConsecutive=max(maxVConsecutive,vConsecutive);
        }


        int hConsecutive=1;
        int maxHConsecutive=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1){
                hConsecutive++;
            }
            else{
                hConsecutive=1;
            }
            maxHConsecutive=max(maxHConsecutive,hConsecutive);
        }

        cout<<maxHConsecutive<<" "<<maxVConsecutive<<endl;

        int side=min(maxHConsecutive,maxVConsecutive)+1;
        return side*side;

    }
};
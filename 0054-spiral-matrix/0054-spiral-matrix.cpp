class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nRows=matrix.size();
        int nCols=matrix[0].size();
        vector<int>ans;

        int rowStart=0,colStart=0,rowEnd=nRows-1,colEnd=nCols-1;
        int total=nRows*nCols;
        int cnt=0;

        while(cnt<total){

            for(int i=colStart;i<=colEnd;i++){
                if(cnt<total){
                    ans.push_back(matrix[rowStart][i]);
                    cnt++;
                }
            }

            rowStart++;

            for(int i=rowStart;i<=rowEnd;i++){
                 if(cnt<total){
                    ans.push_back(matrix[i][colEnd]);
                    cnt++;
                }
            }

            colEnd--;

            for(int i=colEnd;i>=colStart;i--){
                 if(cnt<total){
                    ans.push_back(matrix[rowEnd][i]);
                    cnt++;
                }
            }
            rowEnd--;

            for(int i=rowEnd;i>=rowStart;i--){
                 if(cnt<total){
                    ans.push_back(matrix[i][colStart]);
                    cnt++;
                }
            }
            colStart++;

        }

        return ans;

    }
};
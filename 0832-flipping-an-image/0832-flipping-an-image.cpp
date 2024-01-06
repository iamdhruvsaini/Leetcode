class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                image[i][j]=image[i][j]==0?1:0;
            }
            reverse(image[i].begin(),image[i].end());
        }
        return image;
        
    }
};
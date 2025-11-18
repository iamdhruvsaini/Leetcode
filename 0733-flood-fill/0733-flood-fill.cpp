class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>&vis,int sr,int sc,int color,int newColor){

        vis[sr][sc]=1;
        int n=image.size();
        int m=image[0].size();

        if(image[sr][sc]==color){
            image[sr][sc]=newColor;
        }

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nRow=sr+delRow[i];
            int nCol=sc+delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && image[nRow][nCol]==color){
                dfs(image,vis,nRow,nCol,color,newColor);
            }
        }


    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n=image.size();
        int m=image[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        int startValue=image[sr][sc];
        dfs(image,vis,sr,sc,startValue,color);

        return image;

    }
};
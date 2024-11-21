
class Solution {
public:

    void solve(vector<vector<int>>&mat,int x,int y,string s){
        if(x<0 || x>=mat.size() || y<0 || y>=mat[0].size()){
            return ;
        }
        if(mat[x][y]==1 || mat[x][y]==2){
            return;
        }
        mat[x][y]=3;

        
        if(s=="n"){
            return solve(mat,x-1,y,"n");
        }
         if(s=="w"){
            return solve(mat,x,y-1,"w");
        }
         if(s=="s"){
            return solve(mat,x+1,y,"s");
        }
         if(s=="e"){
            return solve(mat,x,y+1,"e");
        }
        
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>mat(m,vector<int>(n,0));
        for(int i=0;i<guards.size();i++){
            mat[guards[i][0]][guards[i][1]]=1;
        }
        for(int i=0;i<walls.size();i++){
            mat[walls[i][0]][walls[i][1]]=2;
        }
        for(int i=0;i<guards.size();i++){
            solve(mat,guards[i][0]-1,guards[i][1],"n"); 
            solve(mat,guards[i][0]+1,guards[i][1],"s");         
            solve(mat,guards[i][0],guards[i][1]+1,"e");
            solve(mat,guards[i][0],guards[i][1]-1,"w");
        }
        
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)cnt++;
            }
        }
        return cnt;
    }
};
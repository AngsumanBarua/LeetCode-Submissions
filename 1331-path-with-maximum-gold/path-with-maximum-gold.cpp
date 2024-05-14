class Solution {
public:
    int travers(int i,int j,vector <vector <bool>> &vis,int n,int m,int cur,vector<vector<int>>& grid){
        if(i<0 || j<0 || i==n || j==m || grid[i][j]==0 || vis[i][j]){
            return 0;
        }
        vis[i][j]=true;
        int a=max(travers(i+1,j,vis,n,m,grid[i][j],grid),travers(i-1,j,vis,n,m,grid[i][j],grid));
        int b=max(travers(i,j+1,vis,n,m,grid[i][j],grid),travers(i,j-1,vis,n,m,grid[i][j],grid));
        vis[i][j]=false;
        return max(a,b)+grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector <vector <bool>> vis(n,vector <bool> (m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,travers(i,j,vis,n,m,0,grid));
                }
            }
        }
        return ans;
    }
};

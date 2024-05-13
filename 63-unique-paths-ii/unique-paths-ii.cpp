class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int ara[m+1];
        int val=1;
        ara[0]=1;
        if(obstacleGrid[0][0]==1){
            ara[0]=0;
        }
        for(int i=1;i<m;i++){
            if(obstacleGrid[0][i]==1 || ara[0]==0){
                val=0;
            }
            ara[i]=val;
        }
        val=1;
        for(int i=1;i<n;i++){
            if(obstacleGrid[i][0]==1 || ara[0]==0){
                val=0;
            }
            int temp[m+1];
            temp[0]=val;
            for(int j=1;j<m;j++){
                temp[j]=ara[j]+temp[j-1];
                if(obstacleGrid[i][j]==1){
                    temp[j]=0;
                }
                ara[j-1]=temp[j-1];
            }
            ara[m-1]=temp[m-1];
        }
        return ara[m-1];
    }
};
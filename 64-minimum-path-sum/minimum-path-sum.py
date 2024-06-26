class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n=len(grid)
        m=len(grid[0])
        for i in range(1,m):
            grid[0][i]=grid[0][i-1]+grid[0][i]
        
        for i in range(1,n):
            grid[i][0]=grid[i-1][0]+grid[i][0]
        
        for i in range(1,n):
            for j in range(1,m):
                grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j]
                
        
        return grid[n-1][m-1]
        
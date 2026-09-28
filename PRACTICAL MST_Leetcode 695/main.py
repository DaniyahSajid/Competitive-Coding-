class Solution:
    def maxAreaOfIsland(self, grid):
        m,n=len(grid),len(grid[0])
        def dfs(i,j):
            # Stop at boundary or water
            if i<0 or i>=m or j<0 or j>=n or grid[i][j]==0:
                return 0
            grid[i][j]=0  # Mark visited
            # Count current cell and connected land
            return 1+dfs(i+1,j)+dfs(i-1,j)+dfs(i,j+1)+dfs(i,j-1)
        return max(dfs(i,j) for i in range(m) for j in range(n))
# Take input
m=int(input("Enter number of rows: "))
n=int(input("Enter number of columns: "))
grid=[]
print("Enter the grid:")
for _ in range(m):
    grid.append(list(map(int,input().split())))
# Display result
print("Maximum Area of Island:",Solution().maxAreaOfIsland(grid))

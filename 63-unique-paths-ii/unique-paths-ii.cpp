class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int dpFun(vector<vector<int>>& ob,int i,int j,vector<vector<int>>& vis,int n,int m,vector<vector<int>>& dp){
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=0,down=0;
        if(isSafe(i,j+1,n,m) && !vis[i][j+1] && !ob[i][j+1]){
            vis[i][j+1]=1;
            right = dpFun(ob,i,j+1,vis,n,m,dp);
            vis[i][j+1]=0;
        }
        if(isSafe(i+1,j,n,m) && !vis[i+1][j] && !ob[i+1][j]){
            vis[i+1][j]=1;
            down = dpFun(ob,i+1,j,vis,n,m,dp);
            vis[i+1][j]=0;
        }
        
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<int>> vis(n,vector<int>(m,0));
        if(obstacleGrid[0][0]!=1){
             return dpFun(obstacleGrid,0,0,vis,n,m,dp);
        }
       return 0;
    }
};
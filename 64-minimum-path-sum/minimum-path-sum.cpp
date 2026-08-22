class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int dpFun(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis,int n,int m,vector<vector<int>>& dp){
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int cur = INT_MAX;
        vector<vector<int>> dir={{1,0},{0,1}};
        for(auto d : dir){
            if(isSafe(i+d[0],j+d[1],n,m) && !vis[i+d[0]][j+d[1]]){
            vis[i+d[0]][j+d[1]]=1;
            int temp = dpFun(grid,i+d[0],j+d[1],vis,n,m,dp);
            if(temp!=INT_MAX){
                cur = min(cur,temp+grid[i][j]);
            }
            vis[i+d[0]][j+d[1]]=0;
        }
        }
        
        return dp[i][j]=cur;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<int>> vis(n,vector<int>(m,0));
        return dpFun(grid,0,0,vis,n,m,dp);
    }
};
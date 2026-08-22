class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int dpFun(int i,int j,int n,int m,vector<vector<int>>& dp){
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=0,down=0;
        if(isValid(i,j+1,n,m)){
            right=dpFun(i,j+1,n,m,dp);
        }
        if(isValid(i+1,j,n,m)){
            down=dpFun(i+1,j,n,m,dp);
        }
        return dp[i][j]=right+down;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return dpFun(0,0,n,m,dp);
    }
};
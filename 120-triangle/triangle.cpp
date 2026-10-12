class Solution {
public:
    int dpFun(vector<vector<int>>& triangle,int r,int c,int n){
        if(r==n-1) return triangle[r][c];
        int down=triangle[r][c]+dpFun(triangle,r+1,c,n);
        int rightC=triangle[r][c]+dpFun(triangle,r+1,c+1,n);
        return min(down,rightC);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        m--;
        for(int i=n-2;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j+1],dp[i+1][j]);
            }
            m--;
        }
        return dp[0][0];
    }
};
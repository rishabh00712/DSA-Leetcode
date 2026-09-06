class Solution {
public:
    int dpFun(string& s,string& t,int i,int j,int n,int m,vector<vector<int>>& dp){
        if(j==m) return 1;
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,nonTake=0;
        if(s[i]!=t[j]){
            nonTake=dpFun(s,t,i+1,j,n,m,dp);
        }else{
            take=dpFun(s,t,i+1,j+1,n,m,dp);
            nonTake=dpFun(s,t,i+1,j,n,m,dp);
        }
        return dp[i][j]=take+nonTake;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return dpFun(s,t,0,0,s.size(),t.size(),dp);
    }
};
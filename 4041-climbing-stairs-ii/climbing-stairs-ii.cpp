class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                dp[i]=dp[i+1]+cost[i]+1;
            }else if(i==n-2){
                dp[i]=min(dp[i+1]+cost[i]+1,dp[i+2]+cost[i+1]+4);
            }else{
                dp[i]=min({dp[i+1]+cost[i]+1,dp[i+2]+cost[i+1]+4,dp[i+3]+cost[i+2]+9});
            }
        }
        return dp[0];
    }
};
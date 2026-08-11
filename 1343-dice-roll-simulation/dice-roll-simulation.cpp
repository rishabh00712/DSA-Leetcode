class Solution {
public:
    int MOD=1e9+7;
    int getAns(int n, vector<int>& rollMax,int num,int cnt,vector<vector<vector<int>>>&dp){
        if(n==0) return 1;
        int ans=0;
        if(dp[n][num][cnt]!=-1) return dp[n][num][cnt];

        for(int i=1;i<=6;i++){
            if(i==num){
                if(cnt+1 <= rollMax[i-1]){
                    ans=(ans+(getAns(n-1,rollMax,i,cnt+1,dp)%MOD))%MOD;
                }
            }
            else{
                ans=(ans+(getAns(n-1,rollMax,i,1,dp)%MOD))%MOD;
            }
        }
        return dp[n][num][cnt]=ans%MOD;
    }


    int solve(int n, vector<int>& rollMax){

        int ans=0;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(7,vector<int>(16,-1)));
        ans=getAns(n,rollMax,0,0,dp)%MOD;

        return ans;
    }


    int dieSimulator(int n, vector<int>& rollMax) {
        return solve(n,rollMax);    
    }
};
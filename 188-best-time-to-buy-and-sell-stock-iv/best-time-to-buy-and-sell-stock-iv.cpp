class Solution {
public:
    int dpFun(vector<int>& prices,int i,bool canBuy,int n,int k,vector<vector<vector<int>>>& dp){
        if(i==n || k==0)return 0;
        if(dp[i][k][canBuy]!=-1) return dp[i][k][canBuy];
        int totalProfit=0;
        if(canBuy){
            int buy=-prices[i]+dpFun(prices,i+1,false,n,k,dp);
            int dontBuy=dpFun(prices,i+1,canBuy,n,k,dp);
            totalProfit=max(buy,dontBuy);
        }
        if(!canBuy){
            int sell=prices[i]+dpFun(prices,i+1,true,n,k-1,dp);
            int dontSell=dpFun(prices,i+1,canBuy,n,k,dp);
            totalProfit=max(sell,dontSell);
        }
        return dp[i][k][canBuy]=totalProfit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return dpFun(prices,0,true,n,k,dp);
    }
};
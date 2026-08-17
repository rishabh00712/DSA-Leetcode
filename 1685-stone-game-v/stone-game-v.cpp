class Solution {
public:
    int dpFun(int l,int r,vector<int>& preSum,vector<vector<int>>& dp){
        if(l==r) return 0;
        int ans=0;
        if(dp[l][r]!=-1) return dp[l][r];
        for(int i=l+1;i<=r;i++){
            int leftSum ;
            if(l==0){
                leftSum=preSum[i-1];
            }else{
                leftSum = preSum[i-1]-preSum[l-1];
            }
            
            int rightSum = preSum[r]-preSum[i-1];
            int temp=0;
            if(leftSum<rightSum){
                temp=leftSum+dpFun(l,i-1,preSum,dp);
            }else if(leftSum>rightSum){
                temp=rightSum+dpFun(i,r,preSum,dp);
            }else{
                int temp1=leftSum+dpFun(l,i-1,preSum,dp);
                int temp2=rightSum+dpFun(i,r,preSum,dp);
                temp=max(temp1,temp2);
            }
            ans=max(ans,temp);
        }
        return dp[l][r]= ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> preSum(n,0);
        preSum[0]=stoneValue[0];
         vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+stoneValue[i];
        }
        return dpFun(0,n-1,preSum,dp);
    }
};
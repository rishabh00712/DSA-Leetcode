class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        //base case
        dp[n]=0;
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int take=nums[i]+dp[i+2];
            int non_take=dp[i+1];
            dp[i]=max(take,non_take);
        }
        return dp[0];
    }
};

// class Solution {
// public:
//     int dpFun(vector<int>& nums,int ind,int n,vector<int>& dp){
//         if(ind==n){
//             return 0;
//         }
//         if(ind==n-1){
//             return nums[n-1];
//         }
//         if(dp[ind]!=-1) return dp[ind];
//         int rob=nums[ind] + dpFun(nums,ind+2,n,dp);
//         int notRob = dpFun(nums,ind+1,n,dp);
//         return dp[ind]=max(rob,notRob);
//     }
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(),-1);
//         return dpFun(nums,0,nums.size(),dp);
//     }
// };
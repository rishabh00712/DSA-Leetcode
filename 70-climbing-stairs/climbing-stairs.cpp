class Solution {
public:
    int climbStairs(int n) {
        int pre=1;
        int pre_pre=1;
        for(int i=2;i<=n;i++){
            int temp=pre+pre_pre;
            pre_pre=pre;
            pre=temp;
        }
        return pre;
    }
};


// class Solution {
// public:
//     int dpFun(int n,vector<int>& dp){
//         cout<<n<<endl;
//         if(n==0) return 1;
//         //if(n<0) return 0;
//         if(n==1) return 1;//as for 1 index we only have one opetion that jump just one and reach to index 0
//         if(dp[n]!=-1) return dp[n];
//         return dp[n]=dpFun(n-1,dp)+dpFun(n-2,dp);
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1,-1);
//         return dpFun(n,dp);
//     }
// };
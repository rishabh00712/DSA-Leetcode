class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (auto c : coins) {
                if (i >= c && dp[i - c] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// class Solution {
// public:
//     int dpFun(vector<int>& coins, int rem, vector<int>& dp) {
//         if (rem < 0) return INT_MAX;
//         if (rem == 0) return 0;
//         if (dp[rem] != -1) return dp[rem];

//         int mini = INT_MAX;
//         for (int coin : coins) {
//             int temp = dpFun(coins, rem - coin, dp);
//             if (temp != INT_MAX) {
//                 mini = min(mini, temp + 1);
//             }
//         }
//         return dp[rem] = mini;
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount + 1, -1);
//         int res = dpFun(coins, amount, dp);
//         return res == INT_MAX ? -1 : res;
//     }
// };

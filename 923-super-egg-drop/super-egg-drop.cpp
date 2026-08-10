class Solution {
public:
    int superEggDrop(int e, int k) {
        vector<long long> dp(e + 1, 0);
        int moves = 0;

        while (dp[e] < k) {
            moves++;
            for (int i = e; i >= 1; i--) {
                dp[i] = 1 + dp[i] + dp[i - 1];
            }
        }

        return moves;
    }
};

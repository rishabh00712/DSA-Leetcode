class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        int n=rods.size();
        for (int i=0;i<n;i++) {
            unordered_map<int, int> nxt = dp;
            for (auto& j : dp) {
                nxt[j.first + rods[i]] = max(nxt[j.first + rods[i]], j.second);
                nxt[abs(j.first - rods[i])] = max(nxt[abs(j.first - rods[i])],j.second + min(j.first, rods[i]));
            }
            dp = nxt;
        }
        return dp[0];
    }
};
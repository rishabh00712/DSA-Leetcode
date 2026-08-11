class Solution {
public:
    int m, dp[1 << 10][51], mask_sum[1 << 10]; 
    vector<int> F;

    int f(int i, int mask) {
        if(mask == (1 << m) - 1) 
            return 1;

        if(i >= F.size()) 
            return 0;

        int &ret = dp[mask][i];
        
        if(~ret)
            return ret;
        
        ret = f(i + 1, mask);
        int rem = ((1 << m) - 1) ^ mask;

        for(int sub = rem; sub; sub = (sub - 1) & rem) {
            if(mask_sum[sub] > F[i])
                continue;

            ret |= f(i + 1, mask | sub);

            if(ret) 
                return ret;
        }

        return ret;
    }

    bool canDistribute(vector<int>& A, vector<int>& Q) {
        m = Q.size();
        unordered_map<int,int> freq;
        
        for(int x : A) 
            freq[x]++;

        for(auto &[_, cnt] : freq) 
            F.push_back(cnt);
        
        for(int mask = 1; mask < (1 << m); ++mask)
            for(int i = 0; i < m; ++i)
                if(mask & (1 << i))
                    mask_sum[mask] += Q[i];

        memset(dp, -1, sizeof dp);
        return f(0, 0);
    }
};
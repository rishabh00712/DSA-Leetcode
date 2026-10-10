class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {

        long long k = 1LL * k1 + k2;
        int n = nums1.size();

        vector<long long> nums;
        long long high = 0;
        long long totalDiff = 0;

        // Step 1: Create the difference array
        for (int i = 0; i < n; i++) {
            long long d = llabs(1LL * nums1[i] - nums2[i]);
            nums.push_back(d);

            high = max(high, d);
            totalDiff += d;
        }

        // If all differences can become zero
        if (k >= totalDiff) {
            return 0;
        }

        // Step 2: Binary search for the target p
        long long low = 0;
        long long p = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long need = 0;

            for (long long x : nums) {
                if (x > mid) {
                    need += x - mid;
                }
            }

            if (need <= k) {
                p = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Step 3: Reduce all differences greater than p to p
        long long used = 0;

        for (long long& x : nums) {
            if (x > p) {
                used += x - p;
                x = p;
            }
        }

        // Step 4: Apply the remaining operations
        long long remaining = k - used;

        for (long long& x : nums) {
            if (remaining > 0 && x == p) {
                x--;
                remaining--;
            }
        }

        // Step 5: Calculate the sum of squares
        long long ans = 0;

        for (long long x : nums) {
            ans += x * x;
        }

        return ans;
    }
};
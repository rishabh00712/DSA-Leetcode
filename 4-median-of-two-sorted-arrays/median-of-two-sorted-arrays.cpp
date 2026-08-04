class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // Always binary search on the smaller array
        if (n > m) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = n;
        while (low <= high) {
            int i = (low + high) / 2;
            int j = (n + m + 1) / 2 - i;
            //cout<<i<<"i j"<<j<<endl;
            int l1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int r1 = (i == n) ? INT_MAX : nums1[i];
            int r2 = (j == m) ? INT_MAX : nums2[j];
         //   cout<<l1<<" l1 l2 "<<l2<<" "<<r1<<" r1 r2 "<<r2<<endl;
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                high = i - 1;// we will look for the big one so 
            } else if(l2>r1) {// if l2> r1
                low = i + 1;
            }
        }

        return 0.0; // Control never reaches here if input is valid
    }
};

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> m;
        while(i<n){
            m[nums[i]]++;
            
            while(j<=i && m[nums[i]]>k){
                m[nums[j]]--;
                j++;
            }
            
            ans=max(ans,(i-j+1));
            i++;
        }
        return ans;
    }
};
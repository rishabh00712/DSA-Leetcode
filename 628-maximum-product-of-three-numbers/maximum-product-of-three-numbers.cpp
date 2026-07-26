class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int ele1=nums[0];
        int ele2=nums[1];
        int ele3=nums[n];
        int ele4=nums[n-1];
        int ele5=nums[n-2];
        int pro1=ele1*ele2*ele3;
        int pro2=ele3*ele4*ele5;
        return max(pro1,pro2);
    }
};
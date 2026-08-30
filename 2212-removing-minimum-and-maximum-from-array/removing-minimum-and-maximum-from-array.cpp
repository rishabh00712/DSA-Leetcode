class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=INT_MIN,mini=INT_MAX,maxI,minI;
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                maxI=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                minI=i;
            }
        }
        int minFF = minI+1;
        int minFL =  nums.size()-minI;
        int maxFF = maxI+1;
        int maxFL = nums.size()-maxI;

        return min({minFF+maxFL,minFL+maxFF,max(minFF,maxFF),max(minFL,maxFL)});
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int closestDis=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                int absDis=abs(target-sum);
                if(absDis<closestDis){
                    ans=sum;
                    closestDis=absDis;
                }
                if(sum==target){
                    break;
                }
                if(sum<target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};
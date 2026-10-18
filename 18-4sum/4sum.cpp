class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(i+1!=j && nums[j]==nums[j-1]) continue;
                int l=j+1;
                int r=n-1;
                while(l<r){
                    long long sum=1LL* nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1]){
                            l++;
                        }
                        l++;r--;
                    }else if(sum<target){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
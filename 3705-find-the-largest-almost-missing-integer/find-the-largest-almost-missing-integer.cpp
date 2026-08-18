class Solution {
public:
    int helperFun1(vector<int>& nums,int a,int b){
        int fa=0,fb=0;
        for(auto n: nums){
            if(n==a) fa++;
            if(n==b) fb++;
        }
        if(fa>1 && fb>1) return 3;
        if(fa==1 && fb==1) return 2;
        if(fa==1) return 0;
        return 1;
    }
    int helperFun2(vector<int>& nums){
        int maxi=-1;
        vector<int> fiq(51,0);
        for(auto n : nums){
            fiq[n]++;
        }
        for(auto n : nums){
            if(n>maxi){
                if(fiq[n]==1){
                    maxi=n;
                }
            }
        }
        return maxi;
    }
    int helperFun3(vector<int>& nums){
        int maxi=0;
        for(auto n : nums){
            maxi=max(maxi,n);
        }
        return maxi;
    }
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int msn=nums[0];
        int lsn=nums[n-1];
        if(k==1){
            return helperFun2(nums);
        }
        if(n>k){
            int temp = helperFun1(nums,msn,lsn);
            if(temp==0) return msn;
            if(temp==1) return lsn;
            if(temp==2) return max(lsn,msn);
            return -1;
        }
        return helperFun3(nums);
    }
};
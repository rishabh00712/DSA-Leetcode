class Solution {
public:
    bool canDivisor(vector<int>& nums,int mid,int threshold){
        int sum=0;
        for(auto n: nums){
            int temp=(n+mid-1)/mid;
            
            sum+=temp;
        }
       // cout<<mid<<" "<<sum<<endl;
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int r=0;
        for(auto n : nums){
            r=max(r,n);
        }
        int l=1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canDivisor(nums,mid,threshold)){
                //cout<<mid<<endl;
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findSubArr(vector<int>& nums,int total){
        int k=1;
        int sum=0;
        for(auto n: nums){
            
            if(sum+n<=total){
                sum+=n;
                
            }else{
                k++;
                sum=n;
            }
        }
        cout<<k<<" "<<total<<endl;
        return k;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        int maxi=0;
        for(auto n : nums){
            maxi=max(maxi,n);
            sum+=n;
        }
        int l=maxi;
        int h=sum;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int subArr=findSubArr(nums,mid);
            if(subArr<=k){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};